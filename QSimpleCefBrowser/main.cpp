#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <windows.h>
#include "cef3/CefAppImp.h"
#include "qBrowserWindow/QBrowserWindow.h"

// Entry point function for all processes.
int main(int argc, char *argv[])
{
	HINSTANCE hInstance = ::GetModuleHandle(NULL);

	// Provide CEF with command-line arguments.
	CefMainArgs main_args(hInstance);

	void* sandbox_info = NULL;
	
	// CEF applications have multiple sub-processes (render, plugin, GPU, etc)
	// that share the same executable. This function checks the command-line and,
	// if this is a sub-process, executes the appropriate logic.
	int exit_code = CefExecuteProcess(main_args, NULL, sandbox_info);
	if (exit_code >= 0) {
		// The sub-process has completed so return here.
		return exit_code;
	}
	
	//--- main process -----
	QApplication a(argc, argv);

	// Specify CEF global settings here.
	CefSettings settings;
	settings.no_sandbox = true;
	settings.multi_threaded_message_loop = true;

	// CefAppImp implements application-level callbacks for the browser process.
	// It will create the first browser instance in OnContextInitialized() after
	// CEF has initialized.
	CefRefPtr<CefAppImp> app(new CefAppImp);

	// Initialize CEF.
	CefInitialize(main_args, settings, app.get(), sandbox_info);

	//creat window;
	QBrowserWindow* cefWebWindow = new QBrowserWindow(NULL);
	cefWebWindow->init();
	cefWebWindow->show();

	int qt_exit_code = a.exec();

	// Shut down CEF.
	CefShutdown();

	return qt_exit_code;
}
