/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * This file was autogenerated from GrPremulInputFragmentProcessor.fp; do not modify.
 */
#include "GrPremulInputFragmentProcessor.h"
#if SK_SUPPORT_GPU
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "GrTexture.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLPremulInputFragmentProcessor : public GrGLSLFragmentProcessor {
public:
    GrGLSLPremulInputFragmentProcessor() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrPremulInputFragmentProcessor& _outer =
                args.fFp.cast<GrPremulInputFragmentProcessor>();
        (void)_outer;
        fragBuilder->codeAppendf("%s = %s;\n%s.xyz *= %s.w;\n", args.fOutputColor,
                                 args.fInputColor ? args.fInputColor : "half4(1)",
                                 args.fOutputColor,
                                 args.fInputColor ? args.fInputColor : "half4(1)");
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {}
};
GrGLSLFragmentProcessor* GrPremulInputFragmentProcessor::onCreateGLSLInstance() const {
    return new GrGLSLPremulInputFragmentProcessor();
}
void GrPremulInputFragmentProcessor::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                                           GrProcessorKeyBuilder* b) const {}
bool GrPremulInputFragmentProcessor::onIsEqual(const GrFragmentProcessor& other) const {
    const GrPremulInputFragmentProcessor& that = other.cast<GrPremulInputFragmentProcessor>();
    (void)that;
    return true;
}
GrPremulInputFragmentProcessor::GrPremulInputFragmentProcessor(
        const GrPremulInputFragmentProcessor& src)
        : INHERITED(kGrPremulInputFragmentProcessor_ClassID, src.optimizationFlags()) {}
std::unique_ptr<GrFragmentProcessor> GrPremulInputFragmentProcessor::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrPremulInputFragmentProcessor(*this));
}
#endif
