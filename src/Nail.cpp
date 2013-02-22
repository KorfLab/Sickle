//
//  Nail.cpp
//  Sickle
//
//  Created by Paul Lott on 2/21/13.
//  Copyright (c) 2013 Korf Lab, Genome Center, UC Davis, Davis, CA. All rights reserved.
//

#include "Nail.h"
//
//  Sickle.cpp
//  Sickle
//
//  Created by Paul Lott on 2/21/13.
//  Copyright (c) 2013 Korf Lab, Genome Center, UC Davis, Davis, CA. All rights reserved.
//

#include "Sickle.h"
#include "StochHMMlib.h"
#include "p7_config.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "easel.h"
#include "hmmer.h"
#include <iostream>



static char protein[] = "LQCAACKKPFKKASALRRHKATH";

static float hmmer_score (const ESL_ALPHABET *abc, const P7_HMM *hmm, const char *seq) {
	
	P7_BG        *bg     = NULL; /* background */
	P7_PROFILE   *gm     = NULL; /* generic model */
	P7_GMX       *mx     = NULL; /* viterbi matrix */
	ESL_DSQ      *dsq    = NULL; /* digital sequence */
	int           L      = 0;    /* length of sequence */
	float         score;
	
	/* digitize sequence */
	L = strlen(seq);
	esl_abc_CreateDsq(abc, seq, &dsq);
	
	/* background */
	bg = p7_bg_Create(abc);
	p7_bg_SetLength(bg, L);
	
	/* profile */
	gm = p7_profile_Create(hmm->M, abc);
	p7_ProfileConfig(hmm, bg, gm, L, p7_GLOCAL);
	
	/* viterbi */
	mx = p7_gmx_Create(gm->M, L);
	p7_GViterbi(dsq, L, gm, mx, &score);
	
	/* local clean up */
	p7_gmx_Destroy(mx);
	p7_profile_Destroy(gm);
	p7_bg_Destroy(bg);
	free(dsq);
	
	return score;
}


int main (int argc, char ** argv) {
	
	ESL_ALPHABET *abc    = NULL; /* digitial alphabet */
	P7_HMMFILE   *hfp    = NULL; /* hmm file */
	P7_HMM       *hmm    = NULL; /* hmm */
	
	//Hmmer Model File
	char *hmmfile;
	
	//Hmmer Score
	float score;
	
	/* usage */
	if (argc != 2) {
		fprintf(stderr, "%s <hmm file>\n", argv[0]);
		exit(1);
	}
	
	/* Importing HMMER hmm file */
	hmmfile = argv[1];
	
	if (p7_hmmfile_Open(hmmfile, NULL, &hfp) != eslOK)
		p7_Fail("Failed to open HMM file %s", hmmfile);
	
	if (p7_hmmfile_Read(hfp, &abc, &hmm)     != eslOK)
		p7_Fail("Failed to read HMM");
	p7_hmmfile_Close(hfp);
	
	
	//Scoring the sequence with the model
	score = hmmer_score(abc, hmm, protein);
	
	printf("%f %s\n", score, protein);
	
	
	/* global cleanup */
	p7_hmm_Destroy(hmm);
	esl_alphabet_Destroy(abc);
	
	return 0;
}