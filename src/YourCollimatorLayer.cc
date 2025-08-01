#include "YourCollimatorLayer.hh"


YourCollimatorLayer::YourCollimatorLayer(G4double rotationAngle, G4double pRmin, G4double pRmax, G4double pDz){
    this->pRmin = pRmin * mm;
    this->pRmax = pRmax * mm;
    this->pDz = pDz * mm;

    this->pDx1 = 107.67 * mm;
    this->pDx2 = 161.26 * mm;
    this->pDy1 = 36.0910977 * mm;
    this->pDy2 = 236.0910977 * mm;
    this->pDzTrap = 100.0 * mm;

    this->rotationMatrix = new G4RotationMatrix();
    this->rotationMatrix->rotateX(90 * deg);
    this->rotationMatrix->rotateZ((rotationAngle + 270) * deg);

    this->trapezoidRotationMatrix = new G4RotationMatrix();
    this->trapezoidRotationMatrix->rotateX(90 * deg);
    this->trapezoidRotationMatrix->rotateZ(90 * deg);
    this->trapezoidTranslation = G4ThreeVector(0, 95.0 * mm, 0);

    this->BuildTrapezoid();
}

void YourCollimatorLayer::BuildTrapezoid() {
    this->trapezoid = new G4Trap("Trapezoid", this->pDx1, this->pDx2, this->pDy1, this->pDy2, this->pDzTrap);
}

void YourCollimatorLayer::Build(G4LogicalVolume* motherVolume, G4Material* material, G4ThreeVector translation){

    this->collimatorLayerVolume = new G4Tubs("collimatorLayerVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 360.0 * deg);
    this->actualCollimatorLayerVolume = new G4SubtractionSolid("ActualCollimatorLayerVOlume", this->collimatorLayerVolume, this->trapezoid, this->trapezoidRotationMatrix, this->trapezoidTranslation);
    this->collimatorLayerLogicalVolume = new G4LogicalVolume(this->actualCollimatorLayerVolume, material, "ActualCollimatorLayerLogicalVolume");
    this->collimatorLayerPhysicalVolume = new G4PVPlacement(this->rotationMatrix, translation, this->collimatorLayerLogicalVolume, "collimatorLayerPhysicalVolume", motherVolume, false, 0);
    this->InitialiseAttributes();
}

void YourCollimatorLayer::InitialiseAttributes(){
    G4VisAttributes* collimatorLayerVisAttributes = new G4VisAttributes(G4Colour(0.22, 0.216, 0.216, 1.0));
    collimatorLayerVisAttributes->SetVisibility(true);
    collimatorLayerVisAttributes->SetForceSolid(true);
    this->collimatorLayerLogicalVolume->SetVisAttributes(collimatorLayerVisAttributes);
}


YourCollimatorLayer::~YourCollimatorLayer(){
    delete this->rotationMatrix;
    delete this->collimatorLayerVolume;
    delete this->collimatorLayerLogicalVolume;
    delete this->collimatorLayerPhysicalVolume;
    delete this->actualCollimatorLayerVolume;
    delete this->trapezoid;
    delete this->trapezoidRotationMatrix;
}