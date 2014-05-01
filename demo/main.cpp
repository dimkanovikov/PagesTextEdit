#include <QApplication>

#include "../src/QPagesTextEdit.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QPagesTextEdit w;
	w.show();

	return a.exec();
}
