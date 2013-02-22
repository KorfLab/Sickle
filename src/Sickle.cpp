//
//  main.cpp
//  StochHMM_Interaction
//
//  Created by Paul Lott on 9/21/11.
//  Copyright 2011 University of California, Davis. All rights reserved.
//
/* hmmsearch: search profile HMM(s) against a sequence database.
 *
 * SRE, Thu Dec 20 07:07:25 2007 [Janelia]
 * SVN $Id: hmmsearch.c 3152 2010-02-07 22:55:22Z eddys $
 */


#include <string>
#include <iostream>
#include "StochHMMlib.h"


int main (int argc, char* const argv[]) {
	const char * characters[4] = {"A","C","G","T"};
	
	StochHMM::track tr;
	tr.addAlphabetChar(4,characters);
	
	StochHMM::sequence seq;
	std::string sq("ACGTACGTACGTACGTACGT");
	seq.setSeq(sq, &tr);
	
	std::cout << seq.undigitize() << std::endl;
	seq.shuffle();
	std::cout << seq.undigitize() << std::endl;
	
	
//    Sickle::Sickle ZincModel(argv[1]); //!Creates the Sickle class using model input filename from commandline
//    
//    
//    int place = 0;
//    std::string genome("asdf");
//    std::string NucleotideSequence = "ATGAGTTTGTATGATCTCTCTATCATAATCGGGTTT";
//    //!The three preceding variables would normally be passed to Sickle from StochHMM
//    
//    double HMMER_val = ZincModel.HMMER_Fit(place,&genome, &NucleotideSequence);
//    cout << HMMER_val << "\n";
    return 0;
}
