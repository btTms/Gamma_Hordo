#include "YourTopReflectionLayer.hh"
#include <G4ThreeVector.hh>

YourTopReflectionLayer::YourTopReflectionLayer() {
    this->pRmin = 0 * mm;
    this->pRmax = 25.5 * mm;
    this->pDz = 0.25 * mm;
}

void YourTopReflectionLayer::Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial, G4ThreeVector translate) {
    this->topReflectionLayerVolume = new G4Tubs("topReflectionLayerVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 180.0 * deg);
    this->topReflectionLayerLogicalVolume = new G4LogicalVolume(this->topReflectionLayerVolume, buildMaterial, "TopReflectionLayerLogicalVolume");
    this->topReflectionLayerPhysicalVolume = new G4PVPlacement(nullptr, translate, this->topReflectionLayerLogicalVolume, "TopReflectionLayerPhysicalVolume", motherLogicalVolume, false, 0);
    this->InitialiseAttributes();
}

void YourTopReflectionLayer::InitialiseAttributes() {
    G4VisAttributes* topReflectionLayerVisAttributes = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0, 1.0));
    topReflectionLayerVisAttributes->SetForceSolid(true);
    this->topReflectionLayerLogicalVolume->SetVisAttributes(topReflectionLayerVisAttributes);
}

YourTopReflectionLayer::~YourTopReflectionLayer() {
    delete this->topReflectionLayerVolume;
    delete this->topReflectionLayerLogicalVolume;
    delete this->topReflectionLayerPhysicalVolume;
}