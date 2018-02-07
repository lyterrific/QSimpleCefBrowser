#pragma once
#include <QObject>
#include <list>
#include "include/cef_client.h"

class CefBrowserHandlerImp: public QObject,
	public CefClient,
	public CefDisplayHandler,
	public CefLifeSpanHandler,
	public CefFocusHandler,
	public CefLoadHandler
{
	Q_OBJECT

public:
	CefBrowserHandlerImp();

public:
	// CefClient methods:
	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE { return this;}
	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE { return this;}
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE { return this; }
	virtual CefRefPtr<CefFocusHandler> GetFocusHandler() OVERRIDE { return this; }

	// CefDisplayHandler methods:
	virtual void OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title) OVERRIDE;
	virtual void OnAddressChange(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& url) OVERRIDE;

	// CefLifeSpanHandler methods:
	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
	virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

	// CefLoadHandler methods:
	virtual void OnLoadError(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		ErrorCode errorCode,
		const CefString& errorText,
		const CefString& failedUrl) OVERRIDE;

	virtual void OnLoadingStateChange(CefRefPtr<CefBrowser> browser,
		bool isLoading,
		bool canGoBack,
		bool canGoForward) OVERRIDE;

	// CefFocusHandler methods:
	virtual void OnGotFocus(CefRefPtr<CefBrowser> browser) OVERRIDE;

signals:
	void browserCreated();
	void urlChanged(const QString& url);
	void titleChanged(const QString& title);
	void loadingStateChanged(bool isLoading, bool canGoBack, bool canGoForward);
	void webViewGotFocus();

public:
	// Request that all existing browser windows close.
	void CloseAllBrowsers(bool forceClose);
	bool IsClosing() const { return _isClosing; }
	CefRefPtr<CefBrowser> GetBrowser(){	return _browser; }

private:
	// List of existing browser windows. Only accessed on the CEF UI thread.
	typedef std::list<CefRefPtr<CefBrowser>> BrowserList;
	BrowserList _browserList;

	bool _isClosing;
	// child browser window
	CefRefPtr<CefBrowser> _browser;
	// The number of currently existing browser windows. The application will exit
	// when the number reaches 0.
	static int _browserCount;
	// The child browser id
	int _browserId;

private:
	// Include the default reference counting implementation.
	IMPLEMENT_REFCOUNTING(CefBrowserHandlerImp);
};