#ifndef YOURDETECTOR_HH
#define YOURDETECTOR_HH

#include "YourScintillatorCrystal.hh"
#include "YourSideReflectionLayer.hh"
#include "YourTopReflectionLayer.hh"
#include "YourScintillatorOuterCoverage.hh"
#include "YourScintillatorCoverageCap.hh"
#include "YourDetectorBody.hh"
#include "YourCollimator.hh"

class YourDetector{

    public:
        YourDetector(G4double rotationAngle, G4double pRmin1, G4double pRmax1, G4double pDz1,
                                               G4double pRmin2, G4double pRmax2, G4double pDz2,
                                               G4double pRmin3, G4double pRmax3, G4double pDz3);
        ~YourDetector();

        void Build(G4LogicalVolume* motherVolume, G4Material* scintillatorCrystalMaterial, G4ThreeVector translate, G4int id,
                        G4Material* sideReflectionLayerMaterial,
                        G4Material* topReflectionLayerMaterial,
                        G4Material* outerCoverageMaterial,
                        G4Material* scintillatorCoverageCapMaterial,
                        G4Material* detectorBodyMaterial,
                        G4Material* collimatorLayer1Material,
                        G4Material* collimatorLayer2Material,
                        G4Material* collimatorLayer3Material);

    private:

        YourScintillatorCrystal* scintillatorCrystal;
        YourSideReflexionLayer* sideReflectionLayer;
        YourTopReflectionLayer* topReflectionLayer;
        YourScintillatorOuterCoverage* scintillatorOuterCoverage;
        YourScintillatorCoverageCap* scintillatorCoverageCap;
        YourDetectorBody* detectorBody;
        YourCollimator* collimator;

        G4ThreeVector topReflectionLayerOffset, outerCoverageOffset, scintillatorCoverageCapOffset, detectorBodyOffset;
        G4int id;


};


#endif