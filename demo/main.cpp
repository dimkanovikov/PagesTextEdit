#include <QApplication>

#include <QTextDocument>
#include <QCheckBox>

#include "../src/QPagesTextEdit.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QPagesTextEdit w;
	QTextDocument* doc = new QTextDocument;
	doc->setDocumentMargin(20);
	doc->setDefaultFont(QFont("Courier", 12));
	w.setDocument(doc);

	w.setPageSize(30, 10);
	w.setUsePageMode(true);

	w.show();

	return a.exec();
}
