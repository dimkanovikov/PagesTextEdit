#include "PageMetrics.h"

#include <QPaintDevice>


PageMetrics::PageMetrics(QPaintDevice* _device, QPageSize::PageSizeId _pageFormat,
						 QMarginsF _mmPageMargins) :
	m_device(_device)
{
	update(_pageFormat, _mmPageMargins);
}

void PageMetrics::update(QPageSize::PageSizeId _pageFormat, QMarginsF _mmPageMargins)
{
	m_pageFormat = _pageFormat;

	m_mmPageSize = QPageSize(m_pageFormat).rect(QPageSize::Millimeter).size();
	m_mmPageMargins = _mmPageMargins;

	//
	// Рассчитываем значения в пикселах
	//
	const bool x = true, y = false;
	m_pxPageSize =
			QSizeF(mmToPx(m_mmPageSize.width(), x),
				   mmToPx(m_mmPageSize.height(), y));
	m_pxPageMargins =
			QMarginsF(mmToPx(m_mmPageMargins.left(), x),
					  mmToPx(m_mmPageMargins.top(), y),
					  mmToPx(m_mmPageMargins.right(), x),
					  mmToPx(m_mmPageMargins.bottom(), y)
					  );
}

namespace {
	static qreal mmToInches(qreal mm) { return mm * 0.039370147; }
}

qreal PageMetrics::mmToPx(qreal _mm, bool _x) const
{
	return ::mmToInches(_mm) * (_x ? m_device->logicalDpiX() : m_device->logicalDpiY());
}
