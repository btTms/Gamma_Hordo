#include "YourWorldBox.hh"



YourWorldBox::YourWorldBox() {
    this->nistManager = G4NistManager::Instance();
    this->worldSize = 100 * m;
    this->worldMaterial = this->nistManager->FindOrBuildMaterial("G4_AIR");

    this->worldVolume = new G4Box("worldVolume", this->worldSize / 2, this->worldSize / 2, this->worldSize / 2);
    this->worldLogicalVolume = new G4LogicalVolume(this->worldVolume, this->worldMaterial, "logicalWorldVolume");
    this->worldPhysicalVolume = new G4PVPlacement(nullptr, G4ThreeVector(0, 0, 0), this->worldLogicalVolume, "physicalWorld", nullptr, false, 0);
}

YourWorldBox::~YourWorldBox() {

    delete this->worldVolume;
    delete this->worldLogicalVolume;
    delete this->worldPhysicalVolume;
    
}