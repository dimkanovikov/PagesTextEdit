#ifndef PAGESTEXTEDIT_H
#define PAGESTEXTEDIT_H

#include <QTextEdit>

#include "PageMetrics.h"


class PagesTextEdit : public QTextEdit
{
	Q_OBJECT
public:
	explicit PagesTextEdit(QWidget* parent = 0);

	/**
	 * @brief Установить формат страницы
	 */
	void setPageFormat(QPageSize::PageSizeId _pageFormat);

	/**
	 * @brief Настроить поля страницы
	 */
	void setPageMargins(const QMarginsF& _margins);

	/**
	 * @brief Получить режим отображения текста
	 */
	bool usePageMode() const;

public slots:
	/**
	 * @brief Установить режим отображения текста
	 */
	void setUsePageMode(bool _use);

protected:
	/**
	 * @brief Переопределяется для корректировки документа и прорисовки оформления страниц
	 */
	void paintEvent(QPaintEvent* _event);

private:
	/**
	 * @brief Обновить внутреннюю геометрию
	 */
	void updateInnerGeometry();

	/**
	 * @brief Обновить интервал вертикальной прокрутки
	 */
	void updateVerticalScrollRange();

	/**
	 * @brief Нарисовать оформление страниц документа
	 */
	void paintPagesView();

private:
	/**
	 * @brief Режим отображения текста
	 *
	 * true - постраничный
	 * false - сплошной
	 */
	bool m_usePageMode;

	/**
	 * @brief Метрика страницы редактора
	 */
	PageMetrics m_pageMetrics;
};

#endif // PAGESTEXTEDIT_H
