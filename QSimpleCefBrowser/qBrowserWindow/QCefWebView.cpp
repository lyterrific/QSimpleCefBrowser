#include <QCloseEvent>
#include <QDebug>
#include "QBrowserWindow.h"

#define DEFAULT_URL "http://www.baidu.com"

CefRefPtr<CefBrowserHandlerImp> QCefWebView::s_browserHandler = NULL;

QCefWebView::QCefWebView(QWidget *parent) :
	QWidget(parent),
	_browserState(None),
	_needResize(false),
	_needLoad(false),
	_url(DEFAULT_URL)
{
	setAttribute(Qt::WA_NativeWindow);
	setAttribute(Qt::WA_DontCreateNativeAncestors);
	if (!s_browserHandler) {
		s_browserHandler = new CefBrowserHandlerImp();
		connect(s_browserHandler, &CefBrowserHandlerImp::browserCreated, this, &QCefWebView::onBrowserCreated, Qt::QueuedConnection);
		connect(s_browserHandler, &CefBrowserHandlerImp::urlChanged, this, &QCefWebView::urlChanged, Qt::QueuedConnection);
		connect(s_browserHandler, &CefBrowserHandlerImp::titleChanged, this, &QCefWebView::titleChanged, Qt::QueuedConnection);
		connect(s_browserHandler, &CefBrowserHandlerImp::loadingStateChanged, this, &QCefWebView::loadStateChanged, Qt::QueuedConnection);
		connect(s_browserHandler, &CefBrowserHandlerImp::webViewGotFocus, this, &QCefWebView::webViewGotFocus, Qt::QueuedConnection);
	}
}

QCefWebView::~QCefWebView()
{
}

void QCefWebView::closeBrowser(QCloseEvent* event)
{
	qDebug() << "-->>" << __FUNCTION__;
	if (s_browserHandler && !s_browserHandler->IsClosing()) {
		auto browser = s_browserHandler->GetBrowser();
		if (browser.get()) {
			browser->GetHost()->CloseBrowser(false);
		}
		event->ignore();
	}
	else {
		event->accept();
	}
}

void QCefWebView::loadUrl(const QString& url)
{
	_url = url;
	switch (_browserState) {
	case None:
		CreateBrowser(size());
		break;

	case Creating:
		_needLoad = true;
		break;

	default:
		BrowserLoadUrl(url);
	}
}

void QCefWebView::back()
{
	auto browser = GetBrowser();
	if (browser.get()) {
		browser->GoBack();
	}
}

void QCefWebView::forward()
{
	auto browser = GetBrowser();
	if (browser.get()) {
		browser->GoForward();
	}
}

void QCefWebView::refresh()
{
	auto browser = GetBrowser();
	if (browser.get()) {
		browser->Reload();
	}
}

void QCefWebView::stop()
{
	auto browser = GetBrowser();
	if (browser.get()) {
		browser->StopLoad();
	}
}

void QCefWebView::onBrowserCreated()
{
	_browserState = Created;
	if (_needResize) {
		ResizeBrowser(size());
		_needResize = false;
	}
}

void QCefWebView::resizeEvent(QResizeEvent* event)
{
	switch (_browserState) {
	case None:
		CreateBrowser(event->size());
		break;

	case Creating:
		_needResize = true;
		break;

	default:
		ResizeBrowser(event->size());
	}
}

bool QCefWebView::CreateBrowser(const QSize& size)
{
	if (_browserState != None || size.isEmpty()) {
		return false;
	}

	if (_browserState != None) {
		return false;
	}

	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = size.width();
	rect.bottom = size.height();

	CefWindowInfo windowInfo;
	CefBrowserSettings browserSettings;

#ifdef _WIN32
	windowInfo.SetAsChild(reinterpret_cast<HWND>(this->winId()), rect);
#endif
	QString url = _url.isEmpty() ? (DEFAULT_URL) : _url.toString();
	CefBrowserHost::CreateBrowser(windowInfo, s_browserHandler.get(), CefString(url.toStdWString()), browserSettings, NULL);
	_browserState = Creating;

	return true;
}

CefRefPtr<CefBrowser> QCefWebView::GetBrowser() const
{
	CefRefPtr<CefBrowser> browser = nullptr;
	if (s_browserHandler.get()) {
		browser = s_browserHandler->GetBrowser();
	}
	return browser;
}

void QCefWebView::ResizeBrowser(const QSize& size)
{
	if (s_browserHandler.get() && s_browserHandler->GetBrowser()) {
		auto windowHandle = s_browserHandler->GetBrowser()->GetHost()->GetWindowHandle();

		if (windowHandle) {
#ifdef _WIN32
			auto hdwp = BeginDeferWindowPos(1);
			hdwp = DeferWindowPos(hdwp, windowHandle, nullptr, 0, 0, size.width(), size.height(), SWP_NOZORDER);
			EndDeferWindowPos(hdwp);
#endif
		}
	}
}

bool QCefWebView::BrowserLoadUrl(const QUrl& url)
{
	if (!url.isEmpty() && GetBrowser()) {
		CefString cefurl(url.toString().toStdWString());
		GetBrowser()->GetMainFrame()->LoadURL(cefurl);
		return true;
	}
	return false;
}
