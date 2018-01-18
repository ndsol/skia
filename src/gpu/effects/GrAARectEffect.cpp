/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*
 * This file was autogenerated from GrAARectEffect.fp; do not modify.
 */
#include "GrAARectEffect.h"
#if SK_SUPPORT_GPU
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramBuilder.h"
#include "GrTexture.h"
#include "SkSLCPP.h"
#include "SkSLUtil.h"
class GrGLSLAARectEffect : public GrGLSLFragmentProcessor {
public:
    GrGLSLAARectEffect() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrAARectEffect& _outer = args.fFp.cast<GrAARectEffect>();
        (void)_outer;
        auto edgeType = _outer.edgeType();
        (void)edgeType;
        auto rect = _outer.rect();
        (void)rect;
        prevRect = float4(-1.0);
        fRectUniformVar = args.fUniformHandler->addUniform(
                kFragment_GrShaderFlag, kFloat4_GrSLType, kDefault_GrSLPrecision, "rectUniform");
        fragBuilder->codeAppendf(
                "float4 prevRect = float4(%f, %f, %f, %f);\nhalf alpha;\n@switch (%d) {\n    case "
                "0:\n    case 2:\n        alpha = half(all(greaterThan(float4(sk_FragCoord.xy, "
                "%s.zw), float4(%s.xy, sk_FragCoord.xy))) ? 1 : 0);\n        break;\n    "
                "default:\n        half xSub, ySub;\n        xSub = half(min(sk_FragCoord.x - "
                "%s.x, 0.0));\n        xSub += half(min(%s.z - sk_FragCoord.x, 0.0));\n        "
                "ySub = half(min(sk_FragCoord.y - %s.y, 0.0));\n        ySub += half(min(%s.w - "
                "sk_FragCoord.y, 0.0));\n        alpha = half((1",
                prevRect.left(),
                prevRect.top(),
                prevRect.right(),
                prevRect.bottom(),
                (int)_outer.edgeType(),
                args.fUniformHandler->getUniformCStr(fRectUniformVar),
                args.fUniformHandler->getUniformCStr(fRectUniformVar),
                args.fUniformHandler->getUniformCStr(fRectUniformVar),
                args.fUniformHandler->getUniformCStr(fRectUniformVar),
                args.fUniformHandler->getUniformCStr(fRectUniformVar),
                args.fUniformHandler->getUniformCStr(fRectUniformVar));
        fragBuilder->codeAppendf(
                ".0 + max(float(xSub), -1.0)) * (1.0 + max(float(ySub), -1.0)));\n}\n@if (%d == 2 "
                "|| %d == 3) {\n    alpha = half(1.0 - float(alpha));\n}\n%s = %s * alpha;\n",
                (int)_outer.edgeType(),
                (int)_outer.edgeType(),
                args.fOutputColor,
                args.fInputColor ? args.fInputColor : "half4(1)");
    }

private:
    void onSetData(const GrGLSLProgramDataManager& pdman,
                   const GrFragmentProcessor& _proc) override {
        const GrAARectEffect& _outer = _proc.cast<GrAARectEffect>();
        auto edgeType = _outer.edgeType();
        (void)edgeType;
        auto rect = _outer.rect();
        (void)rect;
        UniformHandle& rectUniform = fRectUniformVar;
        (void)rectUniform;

        const SkRect& newRect = GrProcessorEdgeTypeIsAA(edgeType) ? rect.makeInset(.5f, .5f) : rect;
        if (newRect != prevRect) {
            pdman.set4f(rectUniform, newRect.fLeft, newRect.fTop, newRect.fRight, newRect.fBottom);
            prevRect = newRect;
        }
    }
    SkRect prevRect = float4(0);
    UniformHandle fRectUniformVar;
};
GrGLSLFragmentProcessor* GrAARectEffect::onCreateGLSLInstance() const {
    return new GrGLSLAARectEffect();
}
void GrAARectEffect::onGetGLSLProcessorKey(const GrShaderCaps& caps,
                                           GrProcessorKeyBuilder* b) const {
    b->add32((int32_t)fEdgeType);
}
bool GrAARectEffect::onIsEqual(const GrFragmentProcessor& other) const {
    const GrAARectEffect& that = other.cast<GrAARectEffect>();
    (void)that;
    if (fEdgeType != that.fEdgeType) return false;
    if (fRect != that.fRect) return false;
    return true;
}
GrAARectEffect::GrAARectEffect(const GrAARectEffect& src)
        : INHERITED(kGrAARectEffect_ClassID, src.optimizationFlags())
        , fEdgeType(src.fEdgeType)
        , fRect(src.fRect) {}
std::unique_ptr<GrFragmentProcessor> GrAARectEffect::clone() const {
    return std::unique_ptr<GrFragmentProcessor>(new GrAARectEffect(*this));
}
GR_DEFINE_FRAGMENT_PROCESSOR_TEST(GrAARectEffect);
#if GR_TEST_UTILS
std::unique_ptr<GrFragmentProcessor> GrAARectEffect::TestCreate(GrProcessorTestData* d) {
    SkRect rect = SkRect::MakeLTRB(d->fRandom->nextSScalar1(),
                                   d->fRandom->nextSScalar1(),
                                   d->fRandom->nextSScalar1(),
                                   d->fRandom->nextSScalar1());
    std::unique_ptr<GrFragmentProcessor> fp;
    do {
        GrClipEdgeType edgeType =
                static_cast<GrClipEdgeType>(d->fRandom->nextULessThan(kGrClipEdgeTypeCnt));

        fp = GrAARectEffect::Make(edgeType, rect);
    } while (nullptr == fp);
    return fp;
}
#endif
#endif
