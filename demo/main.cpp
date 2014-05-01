#include <QApplication>

#include <QTextDocument>

#include "../src/QPagesTextEdit.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QPagesTextEdit w(0, 10, 2);
	QTextDocument* doc = new QTextDocument;
	doc->setDocumentMargin(20);
	doc->setDefaultFont(QFont("Courier", 12));
	w.setDocument(doc);
	w.show();

	return a.exec();
}
