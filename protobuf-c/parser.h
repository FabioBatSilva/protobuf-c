/*
 * Copyright (c) 2008-2015, Dave Benson and the protobuf-c authors.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*! \file
 *
 * Routines to parse text format protobufs.
 *
 * \author Fabio B. Silva <fabio.bat.silva@gmail.com>
 * \copyright 2008-2015. Licensed under the terms of the [BSD-2-Clause] license.
 */

#ifndef PROTOBUF_C_PARSER_H
#define PROTOBUF_C_PARSER_H

#include "protobuf-c.h"

 /** Structure for parsing API.
 *
 */
typedef struct _ProtobufCParserResult {
    int *error;                           /**< Error code. 0 for success, >0 for failure. */
    char *error_message;                  /**< String with error message. */
    int complete;                         /**< Reports whether the message is complete */
    ProtobufCFileDescriptor * descriptor; /**< The parsed descriptor from the proto file. */
} ProtobufCParserResult;

/** Parse the entire proto \c FILE and construct a \c ProtobufCFileDescriptor representing it.
 *
 */
extern ProtobufCParserResult protobuf_c_parser_from_file(const char* proto_filename);


#endif /* PROTOBUF_C_PARSER_H */