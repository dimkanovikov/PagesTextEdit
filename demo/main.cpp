#include <QApplication>

#include <QTextDocument>
#include <QCheckBox>
#include <QTextFrame>
#include <QTextFrameFormat>

#include "../src/PagesTextEdit.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	PagesTextEdit w;
	QTextDocument* doc = new QTextDocument;
	doc->setDefaultFont(QFont("Courier Prime Cyr", 12));
	w.setDocument(doc);

	w.setPageFormat(QPageSize::A4);
	w.setPageMargins(QMarginsF(37.5, 25, 25, 12.5));
	w.setUsePageMode(true);

	w.resize(600, 400);
	w.show();

	return a.exec();
}
