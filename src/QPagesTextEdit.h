#ifndef QPAGESTEXTEDIT_H
#define QPAGESTEXTEDIT_H

#include <QScrollArea>

class QTextDocument;
class QTextEdit;
class QVBoxLayout;


/**
 * @brief Виджет для постраничного редактирования документов
 */
class QPagesTextEdit : public QScrollArea
{
	Q_OBJECT

public:
	explicit QPagesTextEdit(QWidget* _parent = 0, int _charsInLine = 60, int _linesInPage = 50);

	/**
	 * @brief Получить документ редактора
	 */
	QTextDocument* document() const;

	/**
	 * @brief Установить документ в редактор
	 */
	void setDocument(QTextDocument* _document);

protected:
	/**
	 * @brief Создать копию текстового редактора
	 */
	virtual QTextEdit* createPage();

private slots:
	/**
	 * @brief Изменился текст в каком-либо из редакторов
	 */
	void aboutTextChanged();

private:
	/**
	 * @brief Настроить заданный текстовый редактор
	 */
	void initPage(QTextEdit* _page) const;

	/**
	 * @brief Добавить страницу
	 */
	void addPage();

private:
	/**
	 * @brief Количество символов в строке
	 */
	int m_charsInLine;

	/**
	 * @brief Количество строк на странице
	 */
	int m_linesInPage;

	/**
	 * @brief Компоновщик страниц текста
	 */
	QVBoxLayout* m_pagesLayout;

	/**
	 * @brief Редакторы страниц текста
	 */
	QList<QTextEdit*> m_pages;

	/**
	 * @brief Документ редактора
	 */
	QTextDocument* m_document;
};

#endif // QPAGESTEXTEDIT_H
