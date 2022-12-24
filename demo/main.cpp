#include <QApplication>

#include <QTextDocument>
#include <QCheckBox>
#include <QTextFrame>
#include <QTextFrameFormat>
#include <QMainWindow>

#include "../src/PagesTextEdit.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	
	PagesTextEdit editor;
	QTextDocument* doc = new QTextDocument;
	doc->setDefaultFont(QFont("Courier", 12));
	editor.setDocument(doc);

	editor.setPageFormat(QPageSize::A6);
	editor.setPageMargins(QMarginsF(15, 15, 15, 15));
	editor.setUsePageMode(true);
	editor.setPageNumbersAlignment(Qt::AlignTop | Qt::AlignHCenter);
	
	QMainWindow w;
        w.setCentralWidget(editor);
	w.resize(600, 400);
	w.show();

	return a.exec();
}
