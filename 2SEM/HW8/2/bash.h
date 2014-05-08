#ifndef BASH_H
#define BASH_H

#include <QWidget>
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QDomDocument>
	

/// Class for getting information from bash.im
class Bash : public QWidget
{
	Q_OBJECT
	
public:
	Bash(QWidget *parent = 0);
	~Bash();
	
signals:
	/// signals to reutrn list of replics
	void readyToWork(QWebElementCollection elements);
	
private slots:
	void processReply(bool ok);		
	
private:
	QWebView *view;
	QWebElementCollection elements;
};

#endif // BASH_H
