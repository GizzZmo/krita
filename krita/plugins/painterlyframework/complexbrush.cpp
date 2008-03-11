/*
 *  Copyright (c) 2007 Emanuele Tamponi (emanuele@valinor.it)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "complexbrush.h"
#include <klocale.h>
#include <kiconloader.h>
#include <kcomponentdata.h>
#include <kstandarddirs.h>
#include <kis_debug.h>
#include <kgenericfactory.h>

#include "kis_paintop_registry.h"

#include "kis_complexop.h"

typedef KGenericFactory<ComplexBrush> ComplexBrushFactory;
K_EXPORT_COMPONENT_FACTORY(kritacomplexbrush, ComplexBrushFactory("krita"))

ComplexBrush::ComplexBrush(QObject *parent, const QStringList &)
    : KParts::Plugin(parent)
{
    setComponentData(ComplexBrushFactory::componentData());

    KisPaintOpRegistry *r = KisPaintOpRegistry::instance();
    r->add(KisPaintOpFactorySP(new KisComplexOpFactory));
}

ComplexBrush::~ComplexBrush()
{
}

#include "complexbrush.moc"
