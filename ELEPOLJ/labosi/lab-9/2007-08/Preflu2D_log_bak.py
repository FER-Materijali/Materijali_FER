#! Preflu2D 9.30
loadProject('lab9.FLU')

exportMeshAndPhysicalDescriptionToTRA(fileName='Davor',
                                      coordSys=CoordSys['XY1'],
                                      colorForBlack=Color['Red'],
                                      colorForGreen=Color['Yellow'])

RegionFace['REGIONFACE_1'].magneticAC2D=MagneticAC2DFaceSolidConductor(material=Material['MATERIAL_1'],
                                                                       circuitType=NoCircuit())


RegionFace['REGIONFACE_2'].magneticAC2D=MagneticAC2DFaceVacuum()


meshFaces()

exportMeshAndPhysicalDescriptionToTRA(fileName='dado',
                                      coordSys=CoordSys['XY1'],
                                      colorForBlack=Color['Red'],
                                      colorForGreen=Color['Yellow'])

startMacroTransaction()
RegionFace['INFINITE'].magneticAC2D=MagneticAC2DFaceVacuum()

RegionFace['INFINITE'].visibility=Visibility['VISIBLE']

endMacroTransaction()

exportMeshAndPhysicalDescriptionToTRA(fileName='dad',
                                      coordSys=CoordSys['XY1'],
                                      colorForBlack=Color['Red'],
                                      colorForGreen=Color['Yellow'])

saveProject('lab9.FLU')

closeProject()

exit()
