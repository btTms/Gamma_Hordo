#include "YourCollimator.hh"
#include "YourCollimatorLayer.hh"

YourCollimator::YourCollimator(G4double rotationAngle, G4double pRmin1, G4double pRmax1, G4double pDz1,
                                                       G4double pRmin2, G4double pRmax2, G4double pDz2,
                                                    G4double pRmin3, G4double pRmax3, G4double pDz3) 
{
    this->collimatorLayer1 = new YourCollimatorLayer(rotationAngle, pRmin1, pRmax1, pDz1);
    this->collimatorLayer2 = new YourCollimatorLayer(rotationAngle, pRmin2, pRmax2, pDz2);
    this->collimatorLayer3 = new YourCollimatorLayer(rotationAngle, pRmin3, pRmax3, pDz3);

}

void YourCollimator::Build(G4LogicalVolume* motherVolume, G4Material* collimatorLayer1Material, 
                   G4Material* collimatorLayer2Material, G4Material* collimatorLayer3Material,
                   G4ThreeVector translation)
{
    std::cout << "Building collimator with layers at translation: " << translation << "\n";
    this->collimatorLayer1->Build(motherVolume, collimatorLayer1Material, translation);
    this->collimatorLayer2->Build(motherVolume, collimatorLayer2Material, translation);
    this->collimatorLayer3->Build(motherVolume, collimatorLayer3Material, translation);

}

YourCollimator::~YourCollimator() {
    delete this->collimatorLayer1;
    delete this->collimatorLayer2;
    delete this->collimatorLayer3;
}