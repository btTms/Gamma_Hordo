#include "YourDetector.hh"
#include <G4ThreeVector.hh>


YourDetector::YourDetector(G4double rotationAngle, G4double pRmin1, G4double pRmax1, G4double pDz1,
                                               G4double pRmin2, G4double pRmax2, G4double pDz2,
                                               G4double pRmin3, G4double pRmax3, G4double pDz3) 
{
    this->scintillatorCrystal = new YourScintillatorCrystal();
    this->sideReflectionLayer = new YourSideReflexionLayer();
    this->topReflectionLayer = new YourTopReflectionLayer();
    this->scintillatorOuterCoverage = new YourScintillatorOuterCoverage();
    this->scintillatorCoverageCap = new YourScintillatorCoverageCap();
    this->detectorBody = new YourDetectorBody();
    this->collimator = new YourCollimator(rotationAngle, pRmin1, pRmax1, pDz1,
                                           pRmin2, pRmax2, pDz2,
                                           pRmin3, pRmax3, pDz3);

}

void YourDetector::Build(G4LogicalVolume* motherVolume, G4Material* scintillatorCrystalMaterial, G4ThreeVector translate, G4int id,
                        G4Material* sideReflectionLayerMaterial,
                        G4Material* topReflectionLayerMaterial,
                        G4Material* outerCoverageMaterial,
                        G4Material* scintillatorCoverageCapMaterial,
                        G4Material* detectorBodyMaterial,
                        G4Material* collimatorLayer1Material,
                        G4Material* collimatorLayer2Material,
                        G4Material* collimatorLayer3Material)
{
    this->scintillatorCrystal->Build(motherVolume, scintillatorCrystalMaterial, translate);
    this->sideReflectionLayer->Build(this->scintillatorCrystal->GetLogicalVolume(), sideReflectionLayerMaterial);
    this->id = id;

    if(this->id <= 5){
        this->topReflectionLayerOffset = G4ThreeVector(0, 0, -100.25 * mm);
        this->outerCoverageOffset = G4ThreeVector(0.0 * mm, 0.0 * mm, -0.25 * mm);
        this->scintillatorCoverageCapOffset = G4ThreeVector(0.0 * mm, 0.0 * mm, -101.0 * mm);
        this->detectorBodyOffset = G4ThreeVector(0.0 * mm, 0.0 * mm, 260.0 * mm);
    }
    else{
        this->topReflectionLayerOffset = G4ThreeVector(0, 0, 100.25 * mm);
        this->outerCoverageOffset = G4ThreeVector(0.0 * mm, 0.0 * mm, 0.25 * mm);
        this->scintillatorCoverageCapOffset = G4ThreeVector(0.0 * mm, 0.0 * mm, 101.0 * mm);
        this->detectorBodyOffset = G4ThreeVector(0.0 * mm, 0.0 * mm, -260.0 * mm);
    }

    this->topReflectionLayer->Build(this->scintillatorCrystal->GetLogicalVolume(), topReflectionLayerMaterial, this->topReflectionLayerOffset);
    this->scintillatorOuterCoverage->Build(this->scintillatorCrystal->GetLogicalVolume(), outerCoverageMaterial, this->outerCoverageOffset);
    this->scintillatorCoverageCap->Build(this->scintillatorCrystal->GetLogicalVolume(), scintillatorCoverageCapMaterial, this->scintillatorCoverageCapOffset);
    this->detectorBody->Build(this->scintillatorCrystal->GetLogicalVolume(), detectorBodyMaterial, this->detectorBodyOffset);
    this->collimator->Build(motherVolume, collimatorLayer1Material, collimatorLayer2Material, collimatorLayer3Material, translate);
}

YourDetector::~YourDetector() {
    delete this->scintillatorCrystal;
}