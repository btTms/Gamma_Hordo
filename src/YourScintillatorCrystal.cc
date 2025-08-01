#include "YourScintillatorCrystal.hh"

YourScintillatorCrystal::YourScintillatorCrystal(){
    this->pRmin = 0.0 * mm;
    this->pRmax = 25.0 * mm;
    this->pDz = 100.0 * mm;
    this->rotationMatrix = new G4RotationMatrix();
    this->rotationMatrix->rotateX(90.0 * deg);
}

void YourScintillatorCrystal::Build(G4LogicalVolume* motherVolume, G4Material* material, G4ThreeVector translate){
    this->scintillatorCrystalVolume = new G4Tubs("ScintillatorCrystal", pRmin, pRmax, pDz, 0.0, 1800.0 * deg);
    this->scintillatorCrystalLogicalVolume = new G4LogicalVolume(scintillatorCrystalVolume, material, "ScintillatorCrystalLogical");
    this->scintillatorCrystalPhysicalVolume = new G4PVPlacement(rotationMatrix, translate, scintillatorCrystalLogicalVolume, "ScintillatorCrystalPhysical", motherVolume, false, id);
    this->InitialiseAttributes();
}

void YourScintillatorCrystal::InitialiseAttributes() {
    // greenish color
    G4VisAttributes* visAttributes = new G4VisAttributes(G4Colour(0.325, 0.788, 0.341, 1.0)); // Green color with 50% transparency
    visAttributes->SetForceSolid(true);
    scintillatorCrystalLogicalVolume->SetVisAttributes(visAttributes);
}

YourScintillatorCrystal::~YourScintillatorCrystal() {
    delete scintillatorCrystalVolume;
    delete scintillatorCrystalLogicalVolume;
    delete scintillatorCrystalPhysicalVolume;
    delete rotationMatrix;
}