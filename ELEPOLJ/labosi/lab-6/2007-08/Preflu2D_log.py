#! Preflu2D 9.30
newProject()

saveProject('vj6')

ApplicationMagneticDC2D(domain2D=Domain2DPlane(lengthUnit=LengthUnit['MILLIMETER'],
                                               depth='1'),
                        solverFE=SolverFEAutomatic(),
                        coilCoefficient=CoilCoefficientAutomatic())

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['0',
                      '0'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['0',
                      '-20'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['0',
                      '-40'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['20',
                      '0'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['20',
                      '-20'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-20',
                      '0'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-40',
                      '0'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-40',
                      '-20'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-20',
                      '-20'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-20',
                      '-60'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-20',
                      '40'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['0',
                      '20'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['60',
                      '20'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['60',
                      '-40'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['80',
                      '40'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['80',
                      '-60'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['80',
                      '-4'],
                 nature=Nature['STANDARD'])

Point[17].uvw=['80',
               '-7',
               '0']


PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['80',
                      '-13'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['60',
                      '-13'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['60',
                      '-7'],
                 nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[11],
                      Point[15]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[11],
                      Point[6]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[6],
                      Point[9]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[9],
                      Point[10]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[10],
                      Point[16]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[16],
                      Point[18]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[17],
                      Point[15]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[13],
                      Point[20]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[20],
                      Point[17]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[18],
                      Point[19]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[19],
                      Point[14]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[14],
                      Point[3]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[3],
                      Point[2]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[2],
                      Point[1]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[1],
                      Point[12]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[12],
                      Point[13]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[4],
                      Point[5]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[5],
                      Point[2]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[1],
                      Point[4]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[6],
                      Point[7]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[8],
                      Point[7]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[8],
                      Point[9]],
            nature=Nature['STANDARD'])

buildFaces()

meshFaces()

deleteMesh()

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-120',
                      '140'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['-120',
                      '-160'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['180',
                      '-160'],
                 nature=Nature['STANDARD'])

PointCoordinates(color=Color['White'],
                 visibility=Visibility['VISIBLE'],
                 coordSys=CoordSys['XY1'],
                 uvw=['180',
                      '140'],
                 nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[21],
                      Point[24]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[24],
                      Point[23]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[23],
                      Point[22]],
            nature=Nature['STANDARD'])

LineSegment(color=Color['White'],
            visibility=Visibility['VISIBLE'],
            defPoint=[Point[22],
                      Point[21]],
            nature=Nature['STANDARD'])

buildFaces()

meshFaces()

RegionFace(name='zrak',
           magneticDC2D=MagneticDC2DFaceVacuum(),
           color=Color['Turquoise'],
           visibility=Visibility['VISIBLE'])

Material(name='Material_1',
         propertyBH=PropertyBhNonlinearJmu(initialMur='800',
                                           js='1.2'))

RegionFace(name='zavoj',
           magneticDC2D=MagneticDC2DFaceFormulaConductor(currentDensity='1.5'),
           color=Color['Turquoise'],
           visibility=Visibility['VISIBLE'])

RegionFace(name='ZAVOJ_2',
           magneticDC2D=MagneticDC2DFaceFormulaConductor(currentDensity='-1.5'),
           color=Color['Turquoise'],
           visibility=Visibility['VISIBLE'])

RegionLine(name='rub',
           magneticDC2D=MagneticDC2DLineTangentField(),
           color=Color['Turquoise'],
           visibility=Visibility['VISIBLE'])

assignRegionToFaces(face=[Face[2]],
                    region=RegionFace['ZAVOJ'])

assignRegionToFaces(face=[Face[3]],
                    region=RegionFace['ZAVOJ_2'])

assignRegionToFaces(face=[Face[4]],
                    region=RegionFace['ZRAK'])

LineSegment[23,24,25,26].assignRegion(region=RegionLine['RUB'])

exportMeshAndPhysicalDescriptionToTRA(fileName='mag',
                                      coordSys=CoordSys['XY1'],
                                      colorForBlack=Color['Red'],
                                      colorForGreen=Color['Yellow'])

Material(name='zeljezo',
         propertyBH=PropertyBhNonlinearJmu(initialMur='800',
                                           js='1.2'))

RegionFace(name='zeljezo',
           magneticDC2D=MagneticDC2DFaceMagnetic(material=Material['ZELJEZO']),
           color=Color['Turquoise'],
           visibility=Visibility['VISIBLE'])

RegionFace(name='ZELJEZO_1',
           magneticDC2D=MagneticDC2DFaceMagnetic(material=Material['MATERIAL_1']),
           color=Color['Turquoise'],
           visibility=Visibility['VISIBLE'])

assignRegionToFaces(face=[Face[1]],
                    region=RegionFace['ZELJEZO'])

exportMeshAndPhysicalDescriptionToTRA(fileName='mag',
                                      coordSys=CoordSys['XY1'],
                                      colorForBlack=Color['Red'],
                                      colorForGreen=Color['Yellow'])

saveProject('vj6.FLU')

closeProject()

exit()
