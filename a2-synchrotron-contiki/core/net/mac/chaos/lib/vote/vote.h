/*******************************************************************************
 * BSD 3-Clause License
 *
 * Copyright (c) 2017 Beshr Al Nahas and Olaf Landsiedel.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************/
/*
 * \file
 *         Single-phase Vote library
 * \author
 *         Beshr Al Nahas <beshr@chalmers.se>
 *         Olaf Landsiedel <olafl@chalmers.se>
 */

#ifndef _VOTE_H_
#define _VOTE_H_

#include "chaos.h"
#include "testbed.h"
#include "chaos-config.h"

#define VOTE_SLOT_LEN          (4*(RTIMER_SECOND/1000))    //TODO needs calibration

//force radio off after TWO_PC_ROUND_MAX_SLOTS slots
#if TESTBED == cooja
#define VOTE_ROUND_MAX_SLOTS   (60)
#else
#define VOTE_ROUND_MAX_SLOTS   (350)
#endif

#define VOTE_SLOT_LEN_DCO      (VOTE_SLOT_LEN*CLOCK_PHI)    //TODO needs calibration

int vote_round_begin(const uint16_t round_number, const uint8_t app_id, uint32_t* proposal_value, uint8_t* vote_value, uint8_t** final_flags);

int vote_is_pending(const uint16_t round_count);

int vote_get_flags_length(void);

uint16_t vote_pc_get_off_slot();

int vote_did_agree();

int vote_did_tx();

#endif /* _VOTE_H_ */
