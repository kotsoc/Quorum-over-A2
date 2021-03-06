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
 *         Multi-writer Quorum library 
 * \author
 *         Konstantinos Peratinos <konper@student.chalmers.se>
 */

#ifndef _quorum_mw_H_
#define _quorum_mw_H_

#include "chaos.h"
#include "testbed.h"
#include "chaos-config.h"

#define MAX_SLOT_LEN          (4*(RTIMER_SECOND/1000)+0*(RTIMER_SECOND/1000)/4)    //1 rtimer tick == 2*31.52 us

#ifndef MAX_ROUND_MAX_SLOTS
#warning "define MAX_ROUND_MAX_SLOTS"
#define MAX_ROUND_MAX_SLOTS   (255)
#endif

#define MAX_SLOT_LEN_DCO      (MAX_SLOT_LEN*CLOCK_PHI)    //TODO needs calibration

int quorum_mw_round_begin(const uint16_t round_number, const uint8_t id, uint16_t* value, uint16_t* tag, uint8_t operation, uint16_t* writer_id, uint8_t** final_flags);

int q_is_pending(const uint16_t round_count);

int quorum_mw_get_flags_length(void);

uint16_t quorum_mw_get_off_slot();

uint16_t bit_Count(uint8_t* b);

#endif /* _quorum_mw_H_ */
