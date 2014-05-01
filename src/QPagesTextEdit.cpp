#include "QPagesTextEdit.h"

#include <QTextDocument>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace {
	/**
	 * @brief Расстояние между страницами
	 */
	const int PAGE_MARGIN = 8;
}


QPagesTextEdit::QPagesTextEdit(QWidget* _parent, int _charsInLine, int _linesInPage) :
	QScrollArea(_parent),
	m_charsInLine(_charsInLine),
	m_linesInPage(_linesInPage),
	m_pagesLayout(new QVBoxLayout),
	m_document(new QTextDocument(this))
{
	//
	// Настраиваем виджет
	//
	setWidgetResizable(true);

	//
	// Настраиваем компоновку виджета
	//

	m_pagesLayout->setContentsMargins(QMargins(0, PAGE_MARGIN, 0, PAGE_MARGIN));
	m_pagesLayout->setSpacing(PAGE_MARGIN);
	m_pagesLayout->addStretch();

	QHBoxLayout* layout = new QHBoxLayout;
	layout->setContentsMargins(QMargins());
	layout->setSpacing(0);
	layout->addStretch();
	layout->addLayout(m_pagesLayout);
	layout->addStretch();

	QWidget* contents = new QWidget(this);
	contents->setLayout(layout);
	setWidget(contents);

	//
	// Добавляем пустую страницу
	//
	addPage();
}

QTextDocument* QPagesTextEdit::document() const
{
	return m_document;
}

void QPagesTextEdit::setDocument(QTextDocument* _document)
{
	if (m_document != _document) {
		m_document = _document;

		//
		// Переформировать настройки всех редакторов, т.к. изменился документ
		//
		foreach (QTextEdit* page, m_pages) {
			initPage(page);
		}

		//
		// FIXME: Загрузить текст в документы
		//
	}
}

QTextEdit* QPagesTextEdit::createPage()
{
	return new QTextEdit;
}
#include <QDebug>
void QPagesTextEdit::aboutTextChanged()
{
	if (QTextEdit* page = qobject_cast<QTextEdit*>(sender())) {
		//
		// Если текст не влезает в страницу, отсылаем его следующей
		//

		// ... устанавливаем размер страницы документа
		page->document()->setPageSize(page/*->viewport()*/->rect().size());
//		if (page->document()->pageCount() > 1) {
			qDebug() << page->document()->pageCount();
//		}
	}
}

void QPagesTextEdit::initPage(QTextEdit* _page) const
{
	//
	// Отключить полосы прокрутки редактора
	//
	_page->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	_page->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	//
	// Обновить настройки документа редактора в соответствии с настройками общего документа
	//
	_page->document()->setDocumentMargin(m_document->documentMargin());
	_page->document()->setDefaultFont(m_document->defaultFont());

	//
	// Настроить минимальный размер редактора
	// Учитываются:
	// - кол-во символов в строке
	// - кол-во строк в документе
	// - отступы документа
	//

	QFontMetrics fm(m_document->defaultFont());
	int pageWidth = (m_document->documentMargin() * 2) + (fm.width("W") * m_charsInLine);
	int pageHeight = (m_document->documentMargin() * 2) + (fm.height() * m_linesInPage);
	_page->setFixedSize(pageWidth, pageHeight);

	//
	// Соединяем сигнал об изменении текста в редакторе с обработчиком
	//
	connect(_page, SIGNAL(textChanged()), this, SLOT(aboutTextChanged()));
}

void QPagesTextEdit::addPage()
{
	//
	// Создаём и настраиваем редактор страницы
	//
	QTextEdit* page = createPage();
	initPage(page);

	//
	// Сохраняем редактор
	//
	m_pagesLayout->insertWidget(m_pages.count(), page);
	m_pages.append(page);
}
