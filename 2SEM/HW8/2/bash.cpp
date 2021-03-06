#include "bash.h"
#include <QDebug>

Bash::Bash(QWidget *parent) :
QWidget(parent)
{
	view = new QWebView();
	view->load(QUrl("http://bash.im/"));		
	connect(view, SIGNAL(loadFinished(bool)), this, SLOT(processReply(bool)));
}

Bash::~Bash()
{
	delete view;
}

void Bash::processReply(bool ok)
{
	elements = view->page()->mainFrame()->findAllElements("div[class=text]");
	ratings = view->page()->mainFrame()->findAllElements("span[class=rating]");
	
	message.clear();
	message.push_back(elements);
	message.push_back(ratings);
	
	emit readyToWork(message);			
}
