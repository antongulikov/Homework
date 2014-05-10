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
#include <QVector>
	

/// Class for getting information from bash.im
class Bash : public QWidget
{
	Q_OBJECT
	
public:
	Bash(QWidget *parent = 0);
	~Bash();
	
signals:
	/// signals to reutrn list of replics
	void readyToWork(QVector<QWebElementCollection> message);
	
private slots:
	void processReply(bool ok);		
	
private:
	QWebView *view;	
	QWebElementCollection elements;
	QWebElementCollection ratings;
	QVector<QWebElementCollection> message;
};

#endif // BASH_H
