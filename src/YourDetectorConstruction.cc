#include "YourDetectorConstruction.hh"
#include <G4Types.hh>


YourDetectorConstruction::YourDetectorConstruction() : G4VUserDetectorConstruction(){

    this->SetDetectorPositionsAndAngles();

    this->materialsTable = new Materials();
    this->worldBox = new YourWorldBox();
    this->ground = new YourGround();
    this->externalBackgroundSource = new YourExternalBackgroundSource();
    this->mounting = new YourMounting();
    this->barrel = new YourBarrel();
    this->shielding = new YourShielding();

}

void YourDetectorConstruction::SetDetectorPositionsAndAngles(){
    
    std::ifstream data ("../data/detectorData.dat");
    if(!data.is_open()){
        G4cerr << "Error opening detector positions file!\n";
        return;
    }

    for(G4int i = 0; i < 12; i++){
        G4double x, y, z, angle;
        data >> x >> y >> z >> angle;
        G4ThreeVector currentDetectorPosition(x * mm, y * mm, z * mm);
        this->detectorTranslations.push_back(currentDetectorPosition);
        this->detectorAngles.push_back(angle);
    }
}

void YourDetectorConstruction::BuildDetectors() {

    for(G4int i = 0; i < this->detectorTranslations.size(); i++){

        YourDetector* currentDetector = new YourDetector(this->detectorAngles[i],
                        39.0, 43.0, 145.0,
                        43.0, 73.0, 145.0,
                        74.0, 75.0, 145.0); // it is hard coded right now, might change in the future. 73-74?

        currentDetector->Build(this->worldBox->GetLogicalVolume(), this->materialsTable->GetNatriumIodineMaterial(),
                        this->detectorTranslations[i], i, 
                        this->materialsTable->GetMagnesiumOxidMaterial(),
                        this->materialsTable->GetMagnesiumOxidMaterial(),
                        this->materialsTable->GetAluminiumMaterial(),
                        this->materialsTable->GetAluminiumMaterial(),
                        this->materialsTable->GetAluminiumMaterial(),
                        this->materialsTable->GetCopperMaterial(),
                        this->materialsTable->GetLeadMaterial(),
                        this->materialsTable->GetSteelMaterial());
        this->detectors.push_back(currentDetector);
    }
}


G4VPhysicalVolume* YourDetectorConstruction::Construct(){

    this->ground->Build(this->worldBox->GetLogicalVolume(), this->materialsTable->GetConcreteMaterial());
    this->externalBackgroundSource->Build(this->worldBox->GetLogicalVolume(), this->materialsTable->GetConcreteMaterial());
    this->mounting->Build(this->worldBox->GetLogicalVolume(), this->materialsTable->GetConcreteMaterial());
    this->barrel->Build(this->worldBox->GetLogicalVolume(), this->materialsTable->GetWaterMaterial(),
                        this->worldBox->GetLogicalVolume(), this->materialsTable->GetSteelMaterial(),
                        this->worldBox->GetLogicalVolume(), this->materialsTable->GetSteelMaterial(),
                        this->worldBox->GetLogicalVolume(), this->materialsTable->GetSteelMaterial());

    this->shielding->Build(this->worldBox->GetLogicalVolume(), this->materialsTable->GetLeadMaterial(),
                           this->worldBox->GetLogicalVolume(), this->materialsTable->GetLeadMaterial(),
                           this->worldBox->GetLogicalVolume(), this->materialsTable->GetLeadMaterial());

    this->BuildDetectors();

    return this->worldBox->GetWorldPhysicalVolume();

}


void YourDetectorConstruction::ConstructSDandField(){


}

YourDetectorConstruction::~YourDetectorConstruction() {

}
