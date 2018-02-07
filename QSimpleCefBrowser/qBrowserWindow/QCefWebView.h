#ifndef QCEFWEBWIDGET_H
#define QCEFWEBWIDGET_H

#include <QtWidgets/QWidget>
#include <QUrl>
#include "../cef3/CefBrowserHandlerImp.h"

class QCefWebView :public QWidget
{
	Q_OBJECT

public:
	enum BrowserState {
		None,
		Creating,
		Created
	};

public:
	QCefWebView(QWidget *parent = 0);
	~QCefWebView();

	void closeBrowser(QCloseEvent* event);

public slots:
	void loadUrl(const QString& url);
	void back();
	void forward();
	void refresh();
	void stop();

signals:
	void titleChanged(const QString& title);
	void urlChanged(const QString& url);
	void loadStateChanged(bool isLoading, bool canGoBack, bool canGoForward);
	void webViewGotFocus();

	void loadStarted();
	void loadFinished(bool loadSuccess);

private slots:
	void onBrowserCreated();

protected:
	virtual void resizeEvent(QResizeEvent* event) override;

private:
	bool CreateBrowser(const QSize & size);
	CefRefPtr<CefBrowser> GetBrowser() const;
	void ResizeBrowser(const QSize & size);
	bool BrowserLoadUrl(const QUrl & url);

private:
	static CefRefPtr<CefBrowserHandlerImp> s_browserHandler;

	BrowserState _browserState;
	bool _needResize;
	bool _needLoad;
	QUrl _url;
};

#endif // QCEFWEBWIDGET_H
