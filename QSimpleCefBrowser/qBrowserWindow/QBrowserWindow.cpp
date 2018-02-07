#include <QCloseEvent>
#include <QDebug>
#include "QBrowserWindow.h"

#define BROWSER_WINDOW_NAME "QSimpleCefBrowser"

QBrowserWindow::QBrowserWindow(QMainWindow *parent) :
	QMainWindow(parent),
	backBtn(NULL),
	forwardBtn(NULL),
	refreshBtn(NULL),
	stopBtn(NULL),
	webView(NULL),
	urlEdit(NULL)
{
	resize(1280, 720);
	setAttribute(Qt::WA_NativeWindow, true);
	setAttribute(Qt::WA_DontCreateNativeAncestors, true);
	setFocusPolicy(Qt::FocusPolicy::StrongFocus);
	setWindowTitle(BROWSER_WINDOW_NAME);
}

QBrowserWindow::~QBrowserWindow()
{
}

void QBrowserWindow::init()
{
	QWidget*centerWidget = new QWidget();
	this->setCentralWidget(centerWidget);

	webView = new QCefWebView();
	urlEdit = new QLineEdit();
	connect(urlEdit, &QLineEdit::returnPressed, this, &QBrowserWindow::loadWebUrl);
	connect(webView, &QCefWebView::urlChanged, urlEdit, &QLineEdit::setText);
	connect(webView, &QCefWebView::loadStateChanged, this, &QBrowserWindow::updateBtnState);
	connect(webView, &QCefWebView::webViewGotFocus, this, &QBrowserWindow::onWebViewGotFocus);
	connect(webView, &QCefWebView::titleChanged, this, &QBrowserWindow::onTitleChanged);


	QVBoxLayout* btnLayout = new QVBoxLayout();
	backBtn = new QPushButton("back");
	backBtn->setFixedSize(QSize(50,30));
	connect(backBtn, SIGNAL(clicked()), webView, SLOT(back()));
	forwardBtn = new QPushButton("forward");
	forwardBtn->setFixedSize(QSize(50, 30));
	connect(forwardBtn, SIGNAL(clicked()), webView, SLOT(forward()));
	refreshBtn = new QPushButton("refresh");
	refreshBtn->setFixedSize(QSize(50, 30));
	connect(refreshBtn, SIGNAL(clicked()), webView, SLOT(refresh()));
	stopBtn = new QPushButton("stop");
	stopBtn->setFixedSize(QSize(50, 30));
	connect(stopBtn, SIGNAL(clicked()), webView, SLOT(stop()));

	btnLayout->addWidget(backBtn);
	btnLayout->addWidget(forwardBtn);
	btnLayout->addWidget(refreshBtn);
	btnLayout->addWidget(stopBtn);
	btnLayout->addStretch();

	QHBoxLayout* webLayout = new QHBoxLayout();
	webLayout->addWidget(webView);
	webLayout->addLayout(btnLayout);

	QVBoxLayout* windowLayout = new QVBoxLayout();
	windowLayout->addWidget(urlEdit);
	windowLayout->addLayout(webLayout);

	centerWidget->setLayout(windowLayout);
}

void QBrowserWindow::updateBtnState(bool isLoading, bool canGoBack, bool canGoForward)
{
	if (backBtn && forwardBtn && refreshBtn && stopBtn) {
		refreshBtn->setVisible(!isLoading);
		stopBtn->setVisible(isLoading);
		backBtn->setEnabled(canGoBack);
		forwardBtn->setEnabled(canGoForward);
	}
}

void QBrowserWindow::loadWebUrl()
{
	if (urlEdit && webView) {
		webView->loadUrl(urlEdit->text());
	}
} 

void QBrowserWindow::onWebViewGotFocus()
{
	//handle the focus between QLineEdit and QCefWebView
	if (urlEdit) {
		urlEdit->clearFocus();
	}
}

void QBrowserWindow::onTitleChanged(const QString& title)
{
	setWindowTitle(QString(BROWSER_WINDOW_NAME) + "-" + title);
}

void QBrowserWindow::closeEvent(QCloseEvent* event)
{
	if (webView) {
		webView->closeBrowser(event);
	}
}
