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
	doc->setDefaultFont(QFont("Courier", 12));
	w.setDocument(doc);

	w.setPageFormat(QPageSize::A6);
	w.setPageMargins(QMarginsF(15, 15, 15, 15));
	w.setUsePageMode(true);
	w.setPageNumbersAlignment(Qt::AlignTop | Qt::AlignHCenter);

	w.resize(600, 400);
	w.show();

	return a.exec();
}
