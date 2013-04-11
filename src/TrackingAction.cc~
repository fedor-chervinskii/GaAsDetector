//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//


#include "ExN04TrackingAction.hh"
#include "ExN02PrimaryGeneratorAction.hh"
#include "G4TrackingManager.hh"
#include "G4Track.hh"
#include "TTree.h"
#include "TFile.h"


ExN04TrackingAction::ExN04TrackingAction()
{ 
	t = new TTree("myTree","");	
	t->Branch("cp",&cp,"cp /I");	
	t->Branch("trackid",&trackid,"trackid /I");	
	t->Branch("parentid",&parentid,"parentid /I");
	t->Branch("E0",&E0,"E /F");
	t->Branch("px0",&px0,"px /F");
	t->Branch("py0",&py0,"py /F");
	t->Branch("pz0",&pz0,"pz /F");
	t->Branch("x0",&x0,"x /F");
	t->Branch("y0",&y0,"y /F");
	t->Branch("z0",&z0,"z /F");

	tgamma = new TTree("Gamma","");
	tgamma->Branch("Egamma",&Egamma,"Egamma /F");
}


void ExN04TrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{
	if((aTrack->GetDynamicParticle()->GetCharge())==(0))
	{
		Egamma = aTrack->GetVertexKineticEnergy();
		tgamma->Fill();			
	}
	if((aTrack->GetDynamicParticle()->GetCharge())==(-1))
	{	
		trackid = aTrack->GetTrackID();
		parentid = aTrack->GetParentID();		
		E0 = aTrack->GetVertexKineticEnergy();			
		px0 = aTrack->GetVertexMomentumDirection().x();
		py0 = aTrack->GetVertexMomentumDirection().y();
		pz0 = aTrack->GetVertexMomentumDirection().z();
		x0 = aTrack->GetVertexPosition().x();
		y0 = aTrack->GetVertexPosition().y();
		z0 = aTrack->GetVertexPosition().z();
		cp = 0;		

	        const G4VProcess* ParentProcess = aTrack->GetCreatorProcess();
		G4String ParentProcessName;	
	 	if(ParentProcess!=0){ // no parent process for primary proton
	   		ParentProcessName = ParentProcess->GetProcessName();
	   		if(ParentProcessName=="compt")	cp = 1;
   	    		if(ParentProcessName=="phot")	cp = 2;
   	    		if(ParentProcessName=="eIoni")	cp = 3;
		};
		t->Fill();
 		
	}
}

ExN04TrackingAction::~ExN04TrackingAction()
{
//	G4String Exrt = "40";        
	G4String outputfile = "../results/f_XRT40kV.root";
	TFile f(outputfile,"RECREATE");
	t->Write();
	tgamma->Write();
	f.Close();
}


