#include <QDebug>
#include "CefBrowserHandlerImp.h"
#include "include/base/cef_bind.h"
#include "include/cef_app.h"
#include "include/views/cef_browser_view.h"
#include "include/views/cef_window.h"
#include "include/wrapper/cef_closure_task.h"
#include "include/wrapper/cef_helpers.h"


int CefBrowserHandlerImp::_browserCount = 0;

CefBrowserHandlerImp::CefBrowserHandlerImp()
	:_isClosing(false)
{
}

void CefBrowserHandlerImp::OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title)
{
	CEF_REQUIRE_UI_THREAD();
	qDebug() << "-->>" << __FUNCTION__ << "title:" << title.ToWString().c_str();
	emit titleChanged(QString::fromStdWString(title.ToWString()));
}

void CefBrowserHandlerImp::OnAddressChange(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& url)
{
	CEF_REQUIRE_UI_THREAD();
	qDebug() << "-->>" << __FUNCTION__ << "title:" << url.ToWString().c_str();
	emit urlChanged(QString::fromStdWString(url.ToWString()));
}

void CefBrowserHandlerImp::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();
	if (!_browser.get()) {
		// We need to keep the main child window, but not popup windows
		_browser = browser;
		_browserId = browser->GetIdentifier();
		emit browserCreated();
	}
	else if (browser->IsPopup()) {
		// Add to the list of existing browsers.
		_browserList.push_back(browser);
	}

	++_browserCount;
}

bool CefBrowserHandlerImp::DoClose(CefRefPtr<CefBrowser> browser)
{
	qDebug() << "-->>" << __FUNCTION__;
	CEF_REQUIRE_UI_THREAD();

	// Closing the main window requires special handling. See the DoClose()
	// documentation in the CEF header for a detailed destription of this
	// process.
	if (browser->GetIdentifier() == _browserId) {
		// Set a flag to indicate that the window close should be allowed.
		_isClosing = true;
	}

	// Allow the close. For windowed browsers this will result in the OS close
	// event being sent.
	return false;
}

void CefBrowserHandlerImp::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
	qDebug() << "-->>" << __FUNCTION__;
	CEF_REQUIRE_UI_THREAD();

	if (_browserId == browser->GetIdentifier()) {
		// Free the browser pointer so that the browser can be destroyed
		_browser = nullptr;
	}
	else if (browser->IsPopup()) {
		// Remove from the browser popup list.
		BrowserList::iterator bit = _browserList.begin();
		for (; bit != _browserList.end(); ++bit) {
			if ((*bit)->IsSame(browser)) {
				_browserList.erase(bit);
				break;
			}
		}
	}

	--_browserCount;
}

bool CefBrowserHandlerImp::OnBeforePopup(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& target_url, const CefString& target_frame_name, WindowOpenDisposition target_disposition, bool user_gesture, const CefPopupFeatures& popupFeatures, CefWindowInfo& windowInfo, CefRefPtr<CefClient>& client, CefBrowserSettings& settings, bool* no_javascript_access)
{
	qDebug() << "-->>" << QString::fromStdWString(target_url.ToWString());
	return false;
}

void CefBrowserHandlerImp::OnLoadError(CefRefPtr<CefBrowser> browser, 
	CefRefPtr<CefFrame> frame, 
	ErrorCode errorCode, 
	const CefString& errorText, 
	const CefString& failedUrl)
{
	CEF_REQUIRE_UI_THREAD();

	// Don't display an error for downloaded files.
	if (errorCode == ERR_ABORTED)
		return;

	// Display a load error message.
	std::stringstream ss;
	ss << "<html><body bgcolor=\"white\">"
		"<h2>Failed to load URL " << std::string(failedUrl) <<
		" with error " << std::string(errorText) << " (" << errorCode <<
		").</h2></body></html>";
	frame->LoadString(ss.str(), failedUrl);
}

void CefBrowserHandlerImp::OnLoadingStateChange(CefRefPtr<CefBrowser> browser, bool isLoading, bool canGoBack, bool canGoForward)
{
	CEF_REQUIRE_UI_THREAD();
	if (_browserId == _browser->GetIdentifier()) {
		emit loadingStateChanged(isLoading, canGoBack, canGoForward);
	}
}

void CefBrowserHandlerImp::OnGotFocus(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();
	emit webViewGotFocus();
}

void CefBrowserHandlerImp::CloseAllBrowsers(bool forceClose)
{
	qDebug() << "-->>" << __FUNCTION__;
	if (!CefCurrentlyOn(TID_UI)) {
		// Execute on the UI thread.
		CefPostTask(TID_UI, base::Bind(&CefBrowserHandlerImp::CloseAllBrowsers, this, forceClose));
		return;
	}

	if (_browser == NULL)
		return;

	if (!_browserList.empty()) {
		BrowserList::const_iterator it = _browserList.begin();
		for (; it != _browserList.end(); ++it)
			(*it)->GetHost()->CloseBrowser(forceClose);
		return;
	}
	
	if (_browser.get()) {
		// Request that the main browser close.
		_browser->GetHost()->CloseBrowser(forceClose);
	}
}
