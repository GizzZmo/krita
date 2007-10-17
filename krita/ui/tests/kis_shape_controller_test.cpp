/*
 * Copyright (C) 2007 Boudewijn Rempt <boud@kde.org>
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

#include <QTest>
#include <QCoreApplication>
#include <QSignalSpy>

#include <qtest_kde.h>
#include <kactioncollection.h>
#include <kdebug.h>

#include "KoColorSpace.h"
#include "KoCompositeOp.h"
#include "KoColorSpaceRegistry.h"

#include "kis_doc2.h"
#include "kis_group_layer.h"
#include "kis_image.h"
#include "kis_node_model.h"
#include "kis_nameserver.h"
#include "kis_paint_layer.h"
#include "kis_clone_layer.h"
#include "kis_group_layer.h"
#include "kis_shape_controller.h"
#include "kis_types.h"
#include "kis_transparency_mask.h"

#include "kis_shape_controller_test.h"

void KisShapeControllerTest::testSetImage()
{
    KisDoc2 doc;
    KisNameServer nameServer;
    KisShapeController shapeController (&doc, &nameServer);

    KisImageSP image = new KisImage(0, 512, 512, 0, "shape controller test");
    QCOMPARE( ( int )image->rootLayer()->childCount(), 0 );

    KisLayerSP layer = new KisPaintLayer( image, "test1", OPACITY_OPAQUE );
    image->addLayer( layer );
    QCOMPARE( ( int )image->rootLayer()->childCount(), 1 );

    shapeController.setImage( image );
    QCOMPARE( shapeController.layerMapSize(), 2 );

    shapeController.setImage( 0 );
    QCOMPARE( shapeController.layerMapSize(), 0 );

}

void KisShapeControllerTest::testAddShape()
{

    KisDoc2 doc;
    KisNameServer nameServer;
    KisShapeController shapeController (&doc, &nameServer);

    KisImageSP image = new KisImage(0, 512, 512, 0, "shape controller test");
    QCOMPARE( ( int )image->rootLayer()->childCount(), 0 );

    KisLayerSP layer = new KisPaintLayer( image, "test1", OPACITY_OPAQUE );
    image->addLayer( layer );
    QCOMPARE( ( int )image->rootLayer()->childCount(), 1 );

    shapeController.setImage( image );
    QCOMPARE( shapeController.layerMapSize(), 2 );

    KisGroupLayerSP layer2 = new KisGroupLayer( image, "test2", OPACITY_OPAQUE );
    image->addLayer( layer2.data() );

    QVERIFY( shapeController.shapeForNode( layer2.data() ) != 0 );
    QCOMPARE( ( int )image->rootLayer()->childCount(), 2 );
    QCOMPARE( shapeController.layerMapSize(), 3 );

    KisLayerSP layer3 = new KisCloneLayer( layer, image, "clonetest", OPACITY_OPAQUE );
    image->addLayer( layer3, layer2 );
    QCOMPARE( ( int )image->rootLayer()->childCount(), 2 );
    QCOMPARE( shapeController.layerMapSize(), 4 );

    KisLayerSP layer4 = new KisGroupLayer( image, "grouptest", OPACITY_OPAQUE );
    image->addLayer( layer4, layer2 );
    QCOMPARE( shapeController.layerMapSize(), 5 );

    KisMaskSP mask1 = new KisTransparencyMask();
    image->addNode( mask1.data(), layer3.data() );
    QCOMPARE( shapeController.layerMapSize(), 6 );

    image->removeLayer( layer2 );
    QCOMPARE( shapeController.layerMapSize(), 1 );

    image->removeLayer( layer );
    QCOMPARE( shapeController.layerMapSize(), 0 );

    shapeController.setImage( 0 );


}

void KisShapeControllerTest::testRemoveShape()
{
}

void KisShapeControllerTest::testSetInitialShapeForView()
{
}

void KisShapeControllerTest::testShapeForLayer()
{
}

QTEST_KDEMAIN(KisShapeControllerTest, GUI)
#include "kis_shape_controller_test.moc"
