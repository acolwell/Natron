# ***** BEGIN LICENSE BLOCK *****
# This file is part of Natron <https://natrongithub.github.io/>,
# (C) 2018-2023 The Natron developers
# (C) 2013-2018 INRIA and Alexandre Gauthier-Foichat
#
# Natron is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# Natron is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
# ***** END LICENSE BLOCK *****

TARGET = Engine
TEMPLATE = lib
CONFIG += staticlib
CONFIG += moc
CONFIG += boost boost-serialization-lib qt cairo python shiboken pyside 
QT += core network
greaterThan(QT_MAJOR_VERSION, 4): QT += concurrent
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat

ENGINE_WRAPPER_DIR = Qt$${QT_MAJOR_VERSION}/NatronEngine

!noexpat: CONFIG += expat

# Do not uncomment the following: pyside requires QtGui, because PySide/QtCore/pyside_qtcore_python.h includes qtextdocument.h
#QT -= gui

CONFIG += libmv-flags openmvg-flags glad-flags libtess-flags

include(../global.pri)

log {
    DEFINES += NATRON_LOG
}

precompile_header {
  #message("Using precompiled header")
  # Use Precompiled headers (PCH)
  # we specify PRECOMPILED_DIR, or qmake places precompiled headers in Natron/c++.pch, thus blocking the creation of the Unix executable
  PRECOMPILED_DIR = pch
  PRECOMPILED_HEADER = pch.h
}

#OpenFX C api includes and OpenFX c++ layer includes that are located in the submodule under /libs/OpenFX
INCLUDEPATH += $$PWD/../libs/OpenFX/include
DEPENDPATH  += $$PWD/../libs/OpenFX/include
INCLUDEPATH += $$PWD/../libs/OpenFX_extensions
DEPENDPATH  += $$PWD/../libs/OpenFX_extensions
INCLUDEPATH += $$PWD/../libs/OpenFX/HostSupport/include
DEPENDPATH  += $$PWD/../libs/OpenFX/HostSupport/include
INCLUDEPATH += $$PWD/..
INCLUDEPATH += $$PWD/../Global
INCLUDEPATH += $$PWD/../libs/SequenceParsing

# hoedown
INCLUDEPATH += $$PWD/../libs/hoedown/src

#To overcome wrongly generated #include <...> by shiboken
INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/NatronEngine
DEPENDPATH += $$PWD/NatronEngine
DEPENDPATH += $$PWD/../Global

SOURCES += \
    AbortableRenderInfo.cpp \
    AppInstance.cpp \
    AppManager.cpp \
    AppManagerPrivate.cpp \
    Backdrop.cpp \
    Bezier.cpp \
    BezierCP.cpp \
    BlockingBackgroundRender.cpp \
    CLArgs.cpp \
    Cache.cpp \
    CoonsRegularization.cpp \
    CreateNodeArgs.cpp \
    Curve.cpp \
    CurveSerialization.cpp \
    DefaultShaders.cpp \
    DiskCacheNode.cpp \
    Dot.cpp \
    EffectInstance.cpp \
    EffectInstancePrivate.cpp \
    EffectInstanceRenderRoI.cpp \
    ExistenceCheckThread.cpp \
    FileDownloader.cpp \
    FileSystemModel.cpp \
    FitCurve.cpp \
    FrameEntry.cpp \
    FrameKey.cpp \
    FrameParamsSerialization.cpp \
    GLShader.cpp \
    GPUContextPool.cpp \
    GenericSchedulerThread.cpp \
    GenericSchedulerThreadWatcher.cpp \
    GroupInput.cpp \
    GroupOutput.cpp \
    Hash64.cpp \
    HistogramCPU.cpp \
    HostOverlaySupport.cpp \
    Image.cpp \
    ImageConvert.cpp \
    ImageCopyChannels.cpp \
    ImageKey.cpp \
    ImageMaskMix.cpp \
    ImageParamsSerialization.cpp \
    ImagePlaneDesc.cpp \
    Interpolation.cpp \
    JoinViewsNode.cpp \
    Knob.cpp \
    KnobFactory.cpp \
    KnobFile.cpp \
    KnobSerialization.cpp \
    KnobTypes.cpp \
    LibraryBinary.cpp \
    Log.cpp \
    Lut.cpp \
    Markdown.cpp \
    MemoryFile.cpp \
    MemoryInfo.cpp \
    NoOpBase.cpp \
    Node.cpp \
    NodeDocumentation.cpp \
    NodeGroup.cpp \
    NodeGroupSerialization.cpp \
    NodeInputs.cpp \
    NodeMain.cpp \
    NodeMetadata.cpp \
    NodeName.cpp \
    NodeOverlay.cpp \
    NodeSerialization.cpp \
    Noise.cpp \
    NonKeyParams.cpp \
    NonKeyParamsSerialization.cpp \
    OSGLContext.cpp \
    OSGLContext_mac.cpp \
    OSGLContext_wayland.cpp \
    OSGLContext_win.cpp \
    OSGLContext_x11.cpp \
    OfxClipInstance.cpp \
    OfxEffectInstance.cpp \
    OfxHost.cpp \
    OfxImageEffectInstance.cpp \
    OfxMemory.cpp \
    OfxOverlayInteract.cpp \
    OfxParamInstance.cpp \
    OneViewNode.cpp \
    OutputEffectInstance.cpp \
    OutputSchedulerThread.cpp \
    ParallelRenderArgs.cpp \
    Plugin.cpp \
    PluginMemory.cpp \
    PrecompNode.cpp \
    ProcessHandler.cpp \
    Project.cpp \
    ProjectPrivate.cpp \
    ProjectSerialization.cpp \
    PyAppInstance.cpp \
    PyExprUtils.cpp \
    PyNode.cpp \
    PyNodeGroup.cpp \
    PyParameter.cpp \
    PyRoto.cpp \
    PySideCompat.cpp \
    PyTracker.cpp \
    ReadNode.cpp \
    RectD.cpp \
    RectI.cpp \
    RenderScale.cpp \
    RenderStats.cpp \
    RotoContext.cpp \
    RotoDrawableItem.cpp \
    RotoItem.cpp \
    RotoLayer.cpp \
    RotoPaint.cpp \
    RotoPaintInteract.cpp \
    RotoSmear.cpp \
    RotoStrokeItem.cpp \
    RotoUndoCommand.cpp \
    ScriptObject.cpp \
    Settings.cpp \
    Smooth1D.cpp \
    StandardPaths.cpp \
    StringAnimationManager.cpp \
    TLSHolder.cpp \
    Texture.cpp \
    TextureRect.cpp \
    ThreadPool.cpp \
    TimeLine.cpp \
    Timer.cpp \
    TrackMarker.cpp \
    TrackerContext.cpp \
    TrackerContextPrivate.cpp \
    TrackerFrameAccessor.cpp \
    TrackerNode.cpp \
    TrackerNodeInteract.cpp \
    TrackerUndoCommand.cpp \
    Transform.cpp \
    Utils.cpp \
    ViewerInstance.cpp \
    WriteNode.cpp \
    ../Global/glad_source.c \
    ../Global/FStreamsSupport.cpp \
    ../Global/ProcInfo.cpp \
    ../Global/PythonUtils.cpp \
    ../Global/StrUtils.cpp \
    ../libs/SequenceParsing/SequenceParsing.cpp \
    $${ENGINE_WRAPPER_DIR}/natronengine_module_wrapper.cpp \

HEADERS += \
    AbortableRenderInfo.h \
    AfterQuitProcessingI.h \
    AppInstance.h \
    AppManager.h \
    AppManagerPrivate.h \
    Backdrop.h \
    Bezier.h \
    BezierCP.h \
    BezierCPPrivate.h \
    BezierCPSerialization.h \
    BezierSerialization.h \
    BlockingBackgroundRender.h \
    BufferableObject.h \
    CLArgs.h \
    Cache.h \
    CacheEntry.h \
    CacheEntryHolder.h \
    CacheSerialization.h \
    ChoiceOption.h \
    CoonsRegularization.h \
    CreateNodeArgs.h \
    Curve.h \
    CurvePrivate.h \
    CurveSerialization.h \
    DefaultShaders.h \
    DiskCacheNode.h \
    DockablePanelI.h \
    Dot.h \
    EffectInstance.h \
    EffectInstancePrivate.h \
    EngineFwd.h \
    ExistenceCheckThread.h \
    FeatherPoint.h \
    FileDownloader.h \
    FileSystemModel.h \
    FitCurve.h \
    Format.h \
    FormatSerialization.h \
    FrameEntry.h \
    FrameEntrySerialization.h \
    FrameKey.h \
    FrameParams.h \
    FrameParamsSerialization.h \
    GLShader.h \
    GPUContextPool.h \
    GenericSchedulerThread.h \
    GenericSchedulerThreadWatcher.h \
    GroupInput.h \
    GroupOutput.h \
    Hash64.h \
    HistogramCPU.h \
    HostOverlaySupport.h \
    Image.h \
    ImageKey.h \
    ImageLocker.h \
    ImageParams.h \
    ImageParamsSerialization.h \
    ImagePlaneDesc.h \
    ImageSerialization.h \
    Interpolation.h \
    JoinViewsNode.h \
    KeyHelper.h \
    Knob.h \
    KnobFactory.h \
    KnobFile.h \
    KnobGuiI.h \
    KnobImpl.h \
    KnobSerialization.h \
    KnobTypes.h \
    LRUHashTable.h \
    LibraryBinary.h \
    Log.h \
    LogEntry.h \
    Lut.h \
    Markdown.h \
    MemoryFile.h \
    MemoryInfo.h \
    MergingEnum.h \
    NoOpBase.h \
    Node.h \
    NodeGraphI.h \
    NodeGroup.h \
    NodeGroupSerialization.h \
    NodeGuiI.h \
    NodeMetadata.h \
    NodePrivate.h \
    NodeSerialization.h \
    Noise.h \
    NoiseTables.h \
    NonKeyParams.h \
    NonKeyParamsSerialization.h \
    OSGLContext.h \
    OSGLContext_mac.h \
    OSGLContext_win.h \
    OSGLContext_x11.h \
    OfxClipInstance.h \
    OfxEffectInstance.h \
    OfxHost.h \
    OfxImageEffectInstance.h \
    OfxMemory.h \
    OfxOverlayInteract.h \
    OfxParamInstance.h \
    OneViewNode.h \
    OpenGLViewerI.h \
    OutputEffectInstance.h \
    OutputSchedulerThread.h \
    OverlaySupport.h \
    ParallelRenderArgs.h \
    Plugin.h \
    PluginActionShortcut.h \
    PluginMemory.h \
    PrecompNode.h \
    ProcessHandler.h \
    Project.h \
    ProjectPrivate.h \
    ProjectSerialization.h \
    PyAppInstance.h \
    PyExprUtils.h \
    PyGlobalFunctions.h \
    PyNode.h \
    PyNodeGroup.h \
    PyParameter.h \
    PyRoto.h \
    PyTracker.h \
    ReadNode.h \
    RectD.h \
    RectDSerialization.h \
    RectI.h \
    RectISerialization.h \
    RenderScale.h \
    RenderStats.h \
    RotoContext.h \
    RotoContextPrivate.h \
    RotoContextSerialization.h \
    RotoDrawableItem.h \
    RotoDrawableItemSerialization.h \
    RotoItem.h \
    RotoItemSerialization.h \
    RotoLayer.h \
    RotoLayerSerialization.h \
    RotoPaint.h \
    RotoPaintInteract.h \
    RotoPoint.h \
    RotoSmear.h \
    RotoStrokeItem.h \
    RotoStrokeItemSerialization.h \
    RotoUndoCommand.h \
    ScriptObject.h \
    Settings.h \
    Singleton.h \
    Smooth1D.h \
    StandardPaths.h \
    StringAnimationManager.h \
    TLSHolder.h \
    TLSHolderImpl.h \
    Texture.h \
    TextureRect.h \
    TextureRectSerialization.h \
    ThreadPool.h \
    ThreadStorage.h \
    TimeLine.h \
    TimeLineKeyFrames.h \
    Timer.h \
    TrackMarker.h \
    TrackerContext.h \
    TrackerContextPrivate.h \
    TrackerFrameAccessor.h \
    TrackerNode.h \
    TrackerNodeInteract.h \
    TrackerSerialization.h \
    TrackerUndoCommand.h \
    Transform.h \
    UndoCommand.h \
    UpdateViewerParams.h \
    Utils.h \
    Variant.h \
    VariantSerialization.h \
    ViewIdx.h \
    ViewerInstance.h \
    ViewerInstancePrivate.h \
    WriteNode.h \
    fstream_mingw.h \
    ../Global/Enums.h \
    ../Global/FStreamsSupport.h \
    ../Global/GitVersion.h \
    ../Global/GLIncludes.h \
    ../Global/GlobalDefines.h \
    ../Global/KeySymbols.h \
    ../Global/Macros.h \
    ../Global/ProcInfo.h \
    ../Global/QtCompat.h \
    ../Global/StrUtils.h \
    ../libs/SequenceParsing/SequenceParsing.h \
    ../libs/OpenFX/include/ofxCore.h \
    ../libs/OpenFX/include/ofxDialog.h \
    ../libs/OpenFX/include/ofxImageEffect.h \
    ../libs/OpenFX/include/ofxInteract.h \
    ../libs/OpenFX/include/ofxKeySyms.h \
    ../libs/OpenFX/include/ofxMemory.h \
    ../libs/OpenFX/include/ofxMessage.h \
    ../libs/OpenFX/include/ofxMultiThread.h \
    ../libs/OpenFX/include/ofxNatron.h \
    ../libs/OpenFX/include/ofxOpenGLRender.h \
    ../libs/OpenFX/include/ofxParam.h \
    ../libs/OpenFX/include/ofxParametricParam.h \
    ../libs/OpenFX/include/ofxPixels.h \
    ../libs/OpenFX/include/ofxProgress.h \
    ../libs/OpenFX/include/ofxProperty.h \
    ../libs/OpenFX/include/ofxSonyVegas.h \
    ../libs/OpenFX/include/ofxTimeLine.h \
    ../libs/OpenFX/include/nuke/camera.h \
    ../libs/OpenFX/include/nuke/fnOfxExtensions.h \
    ../libs/OpenFX/include/nuke/fnPublicOfxExtensions.h \
    ../libs/OpenFX/include/tuttle/ofxReadWrite.h \
    ../libs/OpenFX_extensions/ofxhParametricParam.h \
    $${ENGINE_WRAPPER_DIR}/natronengine_python.h \

ENGINE_GENERATED_SOURCES = \
    natron_python_animatedparam_wrapper \
    natron_python_app_wrapper \
    natron_python_appsettings_wrapper \
    natron_python_beziercurve_wrapper \
    natron_python_booleanparam_wrapper \
    natron_python_boolnodecreationproperty_wrapper \
    natron_python_buttonparam_wrapper \
    natron_python_choiceparam_wrapper \
    natron_python_colorparam_wrapper \
    natron_python_colortuple_wrapper \
    natron_python_double2dparam_wrapper \
    natron_python_double2dtuple_wrapper \
    natron_python_double3dparam_wrapper \
    natron_python_double3dtuple_wrapper \
    natron_python_doubleparam_wrapper \
    natron_python_effect_wrapper \
    natron_python_exprutils_wrapper \
    natron_python_fileparam_wrapper \
    natron_python_floatnodecreationproperty_wrapper \
    natron_python_group_wrapper \
    natron_python_groupparam_wrapper \
    natron_python_imagelayer_wrapper \
    natron_python_int2dparam_wrapper \
    natron_python_int2dtuple_wrapper \
    natron_python_int3dparam_wrapper \
    natron_python_int3dtuple_wrapper \
    natron_python_intnodecreationproperty_wrapper \
    natron_python_intparam_wrapper \
    natron_python_itembase_wrapper \
    natron_python_layer_wrapper \
    natron_python_nodecreationproperty_wrapper \
    natron_python_outputfileparam_wrapper \
    natron_python_pageparam_wrapper \
    natron_python_param_wrapper \
    natron_python_parametricparam_wrapper \
    natron_python_pathparam_wrapper \
    natron_python_pycoreapplication_wrapper \
    natron_python_roto_wrapper \
    natron_python_separatorparam_wrapper \
    natron_python_stringnodecreationproperty_wrapper \
    natron_python_stringparam_wrapper \
    natron_python_stringparambase_wrapper \
    natron_python_track_wrapper \
    natron_python_tracker_wrapper \
    natron_python_userparamholder_wrapper \
    natron_rectd_wrapper \
    natron_recti_wrapper \

for(name, ENGINE_GENERATED_SOURCES) {
    SOURCES += $${ENGINE_WRAPPER_DIR}/$${name}.cpp
    HEADERS += $${ENGINE_WRAPPER_DIR}/$${name}.h
}


OTHER_FILES += \
    typesystem_engine.xml

# QMAKE_EXTRA_COMPILERS += SHIBOKEN
macx {

OBJECTIVE_SOURCES += \
    QUrlFix.mm
}
