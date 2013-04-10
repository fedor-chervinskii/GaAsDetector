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

#ifndef ExN04TrackingAction_h
#define ExN04TrackingAction_h 1

#include "G4UserTrackingAction.hh"
#include "TTree.h"


class ExN04TrackingAction : public G4UserTrackingAction {

  public:
    ExN04TrackingAction();
    ~ExN04TrackingAction();
   
	TTree* t;
	Float_t E0;
	Float_t px0;
	Float_t py0;
	Float_t pz0;
	Float_t x0;
	Float_t y0;
	Float_t z0;
	Int_t trackid;	
	Int_t parentid;	
	Int_t cp;	

	TTree* tgamma;
	Float_t Egamma;

    virtual void PreUserTrackingAction(const G4Track*);

};

#endif