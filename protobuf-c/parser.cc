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

#include <stdio.h>
#include <stdlib.h> /* for malloc, free */
#include <string.h> /* for strcmp, strlen, memcpy, memmove, memset */

#include "parser.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/compiler/parser.h>

namespace c {

using namespace google::protobuf;
using namespace google::protobuf::io;
using namespace google::protobuf::compiler;

FileDescriptorProto parse_descriptor_from_file(const char* proto_filename, ProtobufCParserResult* result)
{
    FileDescriptorProto file_desc_proto;

    FILE* proto_file = fopen(proto_filename, "r");
    {
        if (proto_file == NULL) {
            result->error_message = "Cannot open .proto file";
            return file_desc_proto;
        }

        FileInputStream proto_input_stream = fileno(proto_file);

        Tokenizer tokenizer(&proto_input_stream, NULL);

        Parser parser;

        if (!parser.Parse(&tokenizer, file_desc_proto)) {
            result->error_message = "Cannot parse .proto file";
            return file_desc_proto;
        }
    }

    fclose(proto_file);

    if (!file_desc_proto->has_name()) {
        //file_desc_proto->set_name(proto_filename);
    }
}

extern ProtobufCParserResult *protobuf_c_parser_from_file(FILE *proto_file)
{
    FileDescriptorProto descriptor;
    ProtobufCParserResult result;

    return NULL;
}


}  // namespace c