#include "YourScintillatorOuterCoverage.hh"
#include <G4PVPlacement.hh>

YourScintillatorOuterCoverage::YourScintillatorOuterCoverage(){

    this->pRmin = 25.5 * mm;
    this->pRmax = 26.5 * mm;
    this->pDz = 100.25 * mm;
}

void YourScintillatorOuterCoverage::Build(G4LogicalVolume* motherVolume, G4Material* material, G4ThreeVector translate){

    this->ScintillatorOuterCoverageVolume = new G4Tubs("ScintillatorOuterCoverageVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 180.0 * deg);
    this->ScintillatorOuterCoverageLogicalVolume = new G4LogicalVolume(this->ScintillatorOuterCoverageVolume, material, "ScintillatorOuterCoverageLogicalVolume");
    this->ScintillatorOuterCoveragePhysicalVolume = new G4PVPlacement(nullptr, translate, this->ScintillatorOuterCoverageLogicalVolume, "ScintillatorOuterCoveragePhysicalVolume", motherVolume, false, 0);

    this->InitialiseAttributes();
}

void YourScintillatorOuterCoverage::InitialiseAttributes(){

    G4VisAttributes* scintillatorOuterCoverageVisAttributes = new G4VisAttributes(G4Colour(0.902, 0.761, 0.435, 1.0)); // brownish color
    scintillatorOuterCoverageVisAttributes->SetForceSolid(true);
    this->ScintillatorOuterCoverageLogicalVolume->SetVisAttributes(scintillatorOuterCoverageVisAttributes);
}

YourScintillatorOuterCoverage::~YourScintillatorOuterCoverage(){
    delete this->ScintillatorOuterCoverageVolume;
    delete this->ScintillatorOuterCoverageLogicalVolume;
    delete this->ScintillatorOuterCoveragePhysicalVolume;
}