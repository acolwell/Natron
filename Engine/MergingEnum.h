/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <https://natrongithub.github.io/>,
 * (C) 2018-2023 The Natron developers
 * (C) 2013-2018 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

#ifndef MERGINGENUM_H
#define MERGINGENUM_H

// ***** BEGIN PYTHON BLOCK *****
// from <https://docs.python.org/3/c-api/intro.html#include-files>:
// "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
#include <Python.h>
// ***** END PYTHON BLOCK *****

#include "Global/Macros.h"

#include <string>
#include <vector>
#include "Global/Enums.h"
#include "Engine/ChoiceOption.h"
#include "Engine/EngineFwd.h"

NATRON_NAMESPACE_ENTER


namespace Merge {
/**
 * @brief Returns the name of the merge oeprator as described in @openfx-supportext/ofxsMerging.h
 * Keep this in sync with the Merge node's operators otherwise everything will fall apart.
 **/
inline std::string
getOperatorString(NATRON_ENUM::MergingFunctionEnum operation)
{
    switch (operation) {
    case NATRON_ENUM::MergingFunctionEnum::eMergeATop:

        return "atop";
    case NATRON_ENUM::MergingFunctionEnum::eMergeAverage:

        return "average";
    case NATRON_ENUM::MergingFunctionEnum::eMergeColor:

        return "color";
    case NATRON_ENUM::MergingFunctionEnum::eMergeColorBurn:

        return "color-burn";
    case NATRON_ENUM::MergingFunctionEnum::eMergeColorDodge:

        return "color-dodge";
    case NATRON_ENUM::MergingFunctionEnum::eMergeConjointOver:

        return "conjoint-over";
    case NATRON_ENUM::MergingFunctionEnum::eMergeCopy:

        return "copy";
    case NATRON_ENUM::MergingFunctionEnum::eMergeDifference:

        return "difference";
    case NATRON_ENUM::MergingFunctionEnum::eMergeDisjointOver:

        return "disjoint-over";
    case NATRON_ENUM::MergingFunctionEnum::eMergeDivide:

        return "divide";
    case NATRON_ENUM::MergingFunctionEnum::eMergeExclusion:

        return "exclusion";
    case NATRON_ENUM::MergingFunctionEnum::eMergeFreeze:

        return "freeze";
    case NATRON_ENUM::MergingFunctionEnum::eMergeFrom:

        return "from";
    case NATRON_ENUM::MergingFunctionEnum::eMergeGeometric:

        return "geometric";
    case NATRON_ENUM::MergingFunctionEnum::eMergeGrainExtract:

        return "grain-extract";
    case NATRON_ENUM::MergingFunctionEnum::eMergeGrainMerge:

        return "grain-merge";
    case NATRON_ENUM::MergingFunctionEnum::eMergeHardLight:

        return "hard-light";
    case NATRON_ENUM::MergingFunctionEnum::eMergeHue:

        return "hue";
    case NATRON_ENUM::MergingFunctionEnum::eMergeHypot:

        return "hypot";
    case NATRON_ENUM::MergingFunctionEnum::eMergeIn:

        return "in";
    case NATRON_ENUM::MergingFunctionEnum::eMergeLuminosity:

        return "luminosity";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMask:

        return "mask";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMatte:

        return "matte";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMax:

        return "max";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMin:

        return "min";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMinus:

        return "minus";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMultiply:

        return "multiply";
    case NATRON_ENUM::MergingFunctionEnum::eMergeOut:

        return "out";
    case NATRON_ENUM::MergingFunctionEnum::eMergeOver:

        return "over";
    case NATRON_ENUM::MergingFunctionEnum::eMergeOverlay:

        return "overlay";
    case NATRON_ENUM::MergingFunctionEnum::eMergePinLight:

        return "pinlight";
    case NATRON_ENUM::MergingFunctionEnum::eMergePlus:

        return "plus";
    case NATRON_ENUM::MergingFunctionEnum::eMergeReflect:

        return "reflect";
    case NATRON_ENUM::MergingFunctionEnum::eMergeSaturation:

        return "saturation";
    case NATRON_ENUM::MergingFunctionEnum::eMergeScreen:

        return "screen";
    case NATRON_ENUM::MergingFunctionEnum::eMergeSoftLight:

        return "soft-light";
    case NATRON_ENUM::MergingFunctionEnum::eMergeStencil:

        return "stencil";
    case NATRON_ENUM::MergingFunctionEnum::eMergeUnder:

        return "under";
    case NATRON_ENUM::MergingFunctionEnum::eMergeXOR:

        return "xor";
    } // switch

    return "unknown";
} // getOperationString

inline std::string
getOperatorHelpString(NATRON_ENUM::MergingFunctionEnum operation)
{
    switch (operation) {
    case NATRON_ENUM::MergingFunctionEnum::eMergeATop:

        return "Ab + B(1 - a)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeAverage:

        return "(A + B) / 2";
    case NATRON_ENUM::MergingFunctionEnum::eMergeColor:

        return "SetLum(A, Lum(B))";
    case NATRON_ENUM::MergingFunctionEnum::eMergeColorBurn:

        return "darken B towards A";
    case NATRON_ENUM::MergingFunctionEnum::eMergeColorDodge:

        return "brighten B towards A";
    case NATRON_ENUM::MergingFunctionEnum::eMergeConjointOver:

        return "A + B(1-a)/b, A if a > b";
    case NATRON_ENUM::MergingFunctionEnum::eMergeCopy:

        return "A";
    case NATRON_ENUM::MergingFunctionEnum::eMergeDifference:

        return "abs(A-B)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeDisjointOver:

        return "A+B(1-a)/b, A+B if a+b < 1";
    case NATRON_ENUM::MergingFunctionEnum::eMergeDivide:

        return "A/B, 0 if A < 0 and B < 0";
    case NATRON_ENUM::MergingFunctionEnum::eMergeExclusion:

        return "A+B-2AB";
    case NATRON_ENUM::MergingFunctionEnum::eMergeFreeze:

        return "1-sqrt(1-A)/B";
    case NATRON_ENUM::MergingFunctionEnum::eMergeFrom:

        return "B-A";
    case NATRON_ENUM::MergingFunctionEnum::eMergeGeometric:

        return "2AB/(A+B)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeGrainMerge:

        return "B + A - 0.5";
    case NATRON_ENUM::MergingFunctionEnum::eMergeGrainExtract:

        return "B - A + 0.5";
    case NATRON_ENUM::MergingFunctionEnum::eMergeHardLight:

        return "multiply if A < 0.5, screen if A > 0.5";
    case NATRON_ENUM::MergingFunctionEnum::eMergeHue:

        return "SetLum(SetSat(A, Sat(B)), Lum(B))";
    case NATRON_ENUM::MergingFunctionEnum::eMergeHypot:

        return "sqrt(A*A+B*B)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeIn:

        return "Ab";
    case NATRON_ENUM::MergingFunctionEnum::eMergeLuminosity:

        return "SetLum(B, Lum(A))";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMask:

        return "Ba";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMatte:

        return "Aa + B(1-a) (unpremultiplied over)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMax:

        return "max(A, B)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMin:

        return "min(A, B)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMinus:

        return "A-B";
    case NATRON_ENUM::MergingFunctionEnum::eMergeMultiply:

        return "AB, 0 if A < 0 and B < 0";
    case NATRON_ENUM::MergingFunctionEnum::eMergeOut:

        return "A(1-b)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeOver:

        return "A+B(1-a)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeOverlay:

        return "multiply if B<0.5, screen if B>0.5";
    case NATRON_ENUM::MergingFunctionEnum::eMergePinLight:

        return "if B >= 0.5 then max(A, 2*B - 1), min(A, B * 2.0 ) else";
    case NATRON_ENUM::MergingFunctionEnum::eMergePlus:

        return "A+B";
    case NATRON_ENUM::MergingFunctionEnum::eMergeReflect:

        return "A*A / (1 - B)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeSaturation:

        return "SetLum(SetSat(B, Sat(A)), Lum(B))";
    case NATRON_ENUM::MergingFunctionEnum::eMergeScreen:

        return "A+B-AB";
    case NATRON_ENUM::MergingFunctionEnum::eMergeSoftLight:

        return "burn-in if A < 0.5, lighten if A > 0.5";
    case NATRON_ENUM::MergingFunctionEnum::eMergeStencil:

        return "B(1-a)";
    case NATRON_ENUM::MergingFunctionEnum::eMergeUnder:

        return "A(1-b)+B";
    case NATRON_ENUM::MergingFunctionEnum::eMergeXOR:

        return "A(1-b)+B(1-a)";
    } // switch

    return "unknown";
} // getOperationHelpString

inline
NATRON_ENUM::PixmapEnum
getOperatorPixmap(NATRON_ENUM::MergingFunctionEnum operation)
{
    switch (operation) {
    case NATRON_ENUM::MergingFunctionEnum::eMergeATop:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_ATOP;
    case NATRON_ENUM::MergingFunctionEnum::eMergeAverage:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_AVERAGE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeColor:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR;
    case NATRON_ENUM::MergingFunctionEnum::eMergeColorBurn:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR_BURN;
    case NATRON_ENUM::MergingFunctionEnum::eMergeColorDodge:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR_DODGE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeConjointOver:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_CONJOINT_OVER;
    case NATRON_ENUM::MergingFunctionEnum::eMergeCopy:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_COPY;
    case NATRON_ENUM::MergingFunctionEnum::eMergeDifference:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_DIFFERENCE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeDisjointOver:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_DISJOINT_OVER;
    case NATRON_ENUM::MergingFunctionEnum::eMergeDivide:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_DIVIDE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeExclusion:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_EXCLUSION;
    case NATRON_ENUM::MergingFunctionEnum::eMergeFreeze:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_FREEZE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeFrom:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_FROM;
    case NATRON_ENUM::MergingFunctionEnum::eMergeGeometric:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_GEOMETRIC;
    case NATRON_ENUM::MergingFunctionEnum::eMergeGrainExtract:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_GRAIN_EXTRACT;
    case NATRON_ENUM::MergingFunctionEnum::eMergeGrainMerge:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_GRAIN_MERGE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeHardLight:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_HARD_LIGHT;
    case NATRON_ENUM::MergingFunctionEnum::eMergeHue:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_HUE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeHypot:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_HYPOT;
    case NATRON_ENUM::MergingFunctionEnum::eMergeIn:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_IN;
    case NATRON_ENUM::MergingFunctionEnum::eMergeLuminosity:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_LUMINOSITY;
    case NATRON_ENUM::MergingFunctionEnum::eMergeMask:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_MASK;
    case NATRON_ENUM::MergingFunctionEnum::eMergeMatte:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_MATTE;
    case NATRON_ENUM::MergingFunctionEnum::eMergeMax:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_MAX;
    case NATRON_ENUM::MergingFunctionEnum::eMergeMin:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_MIN;
    case NATRON_ENUM::MergingFunctionEnum::eMergeMinus:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_MINUS;
    case NATRON_ENUM::MergingFunctionEnum::eMergeMultiply:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_MULTIPLY;
    case NATRON_ENUM::MergingFunctionEnum::eMergeOut:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_OUT;
    case NATRON_ENUM::MergingFunctionEnum::eMergeOver:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_OVER;
    case NATRON_ENUM::MergingFunctionEnum::eMergeOverlay:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_OVERLAY;
    case NATRON_ENUM::MergingFunctionEnum::eMergePinLight:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_PINLIGHT;
    case NATRON_ENUM::MergingFunctionEnum::eMergePlus:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_PLUS;
    case NATRON_ENUM::MergingFunctionEnum::eMergeReflect:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_REFLECT;
    case NATRON_ENUM::MergingFunctionEnum::eMergeSaturation:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_SATURATION;
    case NATRON_ENUM::MergingFunctionEnum::eMergeScreen:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_SCREEN;
    case NATRON_ENUM::MergingFunctionEnum::eMergeSoftLight:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_SOFT_LIGHT;
    case NATRON_ENUM::MergingFunctionEnum::eMergeStencil:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_STENCIL;
    case NATRON_ENUM::MergingFunctionEnum::eMergeUnder:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_UNDER;
    case NATRON_ENUM::MergingFunctionEnum::eMergeXOR:

        return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_XOR;
    } // switch
    return NATRON_ENUM::PixmapEnum::NATRON_PIXMAP_MERGE_OVER;
} // getOperatorPixmap

///Keep this in sync with the MergeOperatorEnum !
inline void
getOperatorStrings(std::vector<ChoiceOption>* operators)
{
    operators->resize((int)NATRON_ENUM::MergingFunctionEnum::eMergeXOR + 1);

    for (std::size_t i = 0; i < operators->size(); ++i) {

        ChoiceOption& option = (*operators)[i];

        option.id = Merge::getOperatorString( (NATRON_ENUM::MergingFunctionEnum)i );
        option.tooltip = Merge::getOperatorHelpString( (NATRON_ENUM::MergingFunctionEnum)i );
    }
}
} // namespace Merge

NATRON_NAMESPACE_EXIT

#endif // MERGINGENUM_H
