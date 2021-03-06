﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//       LottieGen version:
//           7.0.0-build.57+g2cc4f0c931
//       
//       Command:
//           LottieGen -Language Cppwinrt -InputFile Controls_08_Back.json
//       
//       Input file:
//           Controls_08_Back.json (3678 bytes created 18:12-08:00 Nov 19 2020)
//       
//       LottieGen source:
//           http://aka.ms/Lottie
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
// ___________________________________________________________
// |       Object stats       | UAP v11 count | UAP v7 count |
// |__________________________|_______________|______________|
// | All CompositionObjects   |            46 |           36 |
// |--------------------------+---------------+--------------|
// | Expression animators     |             4 |            3 |
// | KeyFrame animators       |             3 |            2 |
// | Reference parameters     |             5 |            4 |
// | Expression operations    |             0 |            0 |
// |--------------------------+---------------+--------------|
// | Animated brushes         |             - |            - |
// | Animated gradient stops  |             - |            - |
// | ExpressionAnimations     |             1 |            1 |
// | PathKeyFrameAnimations   |             1 |            - |
// |--------------------------+---------------+--------------|
// | ContainerVisuals         |             1 |            1 |
// | ShapeVisuals             |             1 |            1 |
// |--------------------------+---------------+--------------|
// | ContainerShapes          |             1 |            1 |
// | CompositionSpriteShapes  |             1 |            1 |
// |--------------------------+---------------+--------------|
// | Brushes                  |             1 |            1 |
// | Gradient stops           |             - |            - |
// | CompositionVisualSurface |             - |            - |
// -----------------------------------------------------------
#include "pch.h"
#include "Controls_08_Back.h"
#include <winrt/Windows.Foundation.Metadata.h>
#include <winrt/Windows.UI.Composition.h>
#include "d2d1.h"
#include <d2d1_1.h>
#include <d2d1helper.h>
#include <Windows.Graphics.Interop.h>
#include <winrt/Windows.Graphics.Effects.h>

using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Numerics;
using namespace winrt::Windows::Graphics;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Composition;
using TimeSpan = winrt::Windows::Foundation::TimeSpan;

namespace winrt::Microsoft::UI::Xaml::Controls::AnimatedVisuals
{
    CppWinRTActivatableClassWithBasicFactory(Controls_08_Back)
}
#include "AnimatedVisuals\Controls_08_Back.g.cpp"

class CanvasGeometry : public winrt::implements<CanvasGeometry,
    IGeometrySource2D,
    Windows::Graphics::IGeometrySource2DInterop>
{
    winrt::com_ptr<ID2D1Geometry> _geometry{ nullptr };

public:
    CanvasGeometry(winrt::com_ptr<ID2D1Geometry> geometry)
        : _geometry{ geometry }
    { }

    // IGeometrySource2D.
    winrt::com_ptr<ID2D1Geometry> Geometry() { return _geometry; }

    // IGeometrySource2DInterop.
    IFACEMETHODIMP GetGeometry(ID2D1Geometry** value) override
    {
        _geometry.copy_to(value);
        return S_OK;
    }

    // IGeometrySource2DInterop.
    IFACEMETHODIMP TryGetGeometryUsingFactory(ID2D1Factory*, ID2D1Geometry**) override
    {
        return E_NOTIMPL;
    }
};
class Controls_08_Back_AnimatedVisual_UAPv11 : public winrt::implements<Controls_08_Back_AnimatedVisual_UAPv11,
        winrt::Microsoft::UI::Xaml::Controls::IAnimatedVisual,
        IClosable>
{
    winrt::com_ptr<ID2D1Factory> _d2dFactory{ nullptr };
    static constexpr int64_t c_durationTicks{ 10000000L };
    Compositor const _c{ nullptr };
    ExpressionAnimation const _reusableExpressionAnimation{ nullptr };
    CompositionPath _path_0{ nullptr };
    CompositionPath _path_1{ nullptr };
    CompositionPath _path_2{ nullptr };
    ContainerVisual _root{ nullptr };
    CubicBezierEasingFunction _cubicBezierEasingFunction_0{ nullptr };
    ExpressionAnimation _rootProgress{ nullptr };
    StepEasingFunction _holdThenStepEasingFunction{ nullptr };
    StepEasingFunction _stepThenHoldEasingFunction{ nullptr };

    static void StartProgressBoundAnimation(
        CompositionObject target,
        winrt::hstring animatedPropertyName,
        CompositionAnimation animation,
        ExpressionAnimation controllerProgressExpression)
    {
        target.StartAnimation(animatedPropertyName, animation);
        const auto controller = target.TryGetAnimationController(animatedPropertyName);
        controller.Pause();
        controller.StartAnimation(L"Progress", controllerProgressExpression);
    }

    PathKeyFrameAnimation CreatePathKeyFrameAnimation(float initialProgress, CompositionPath initialValue, CompositionEasingFunction initialEasingFunction)
    {
        const auto result = _c.CreatePathKeyFrameAnimation();
        result.Duration(TimeSpan{ c_durationTicks });
        result.InsertKeyFrame(initialProgress, initialValue, initialEasingFunction);
        return result;
    }

    ScalarKeyFrameAnimation CreateScalarKeyFrameAnimation(float initialProgress, float initialValue, CompositionEasingFunction initialEasingFunction)
    {
        const auto result = _c.CreateScalarKeyFrameAnimation();
        result.Duration(TimeSpan{ c_durationTicks });
        result.InsertKeyFrame(initialProgress, initialValue, initialEasingFunction);
        return result;
    }

    Vector2KeyFrameAnimation CreateVector2KeyFrameAnimation(float initialProgress, winrt::float2 initialValue, CompositionEasingFunction initialEasingFunction)
    {
        const auto result = _c.CreateVector2KeyFrameAnimation();
        result.Duration(TimeSpan{ c_durationTicks });
        result.InsertKeyFrame(initialProgress, initialValue, initialEasingFunction);
        return result;
    }

    CompositionSpriteShape CreateSpriteShape(CompositionGeometry geometry, winrt::float3x2 transformMatrix, CompositionBrush fillBrush)
    {
        const auto result = _c.CreateSpriteShape(geometry);
        result.TransformMatrix(transformMatrix);
        result.FillBrush(fillBrush);
        return result;
    }

    winrt::com_ptr<CanvasGeometry> Geometry_0()
    {
        winrt::com_ptr<ID2D1PathGeometry> path{ nullptr };
        winrt::check_hresult(_d2dFactory->CreatePathGeometry(path.put()));
        winrt::com_ptr<ID2D1GeometrySink> sink{ nullptr };
        winrt::check_hresult(path->Open(sink.put()));
        sink->SetFillMode(D2D1_FILL_MODE_WINDING);
        sink->BeginFigure({ 32.5F, 2.21000004F }, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddBezier({ { 32.5F, 2.21000004F }, { -24.7329998F, 2.21000004F }, { -24.7329998F, 2.21000004F } });
        sink->AddBezier({ { -24.7329998F, 2.21000004F }, { 0.317999989F, 29.3920002F }, { 0.317999989F, 29.3920002F } });
        sink->AddBezier({ { 0.317999989F, 29.3920002F }, { -2.54699993F, 32.5F }, { -2.54699993F, 32.5F } });
        sink->AddBezier({ { -2.54699993F, 32.5F }, { -32.5F, 0.0F }, { -32.5F, 0.0F } });
        sink->AddBezier({ { -32.5F, 0.0F }, { -2.54699993F, -32.5F }, { -2.54699993F, -32.5F } });
        sink->AddBezier({ { -2.54699993F, -32.5F }, { 0.317999989F, -29.3920002F }, { 0.317999989F, -29.3920002F } });
        sink->AddBezier({ { 0.317999989F, -29.3920002F }, { -24.7329998F, -2.21000004F }, { -24.7329998F, -2.21000004F } });
        sink->AddBezier({ { -24.7329998F, -2.21000004F }, { 32.5F, -2.21000004F }, { 32.5F, -2.21000004F } });
        sink->AddBezier({ { 32.5F, -2.21000004F }, { 32.5F, 2.21000004F }, { 32.5F, 2.21000004F } });
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        winrt::check_hresult(sink->Close());
        auto result = winrt::make_self<CanvasGeometry>(path);
        return result;
    }

    winrt::com_ptr<CanvasGeometry> Geometry_1()
    {
        winrt::com_ptr<ID2D1PathGeometry> path{ nullptr };
        winrt::check_hresult(_d2dFactory->CreatePathGeometry(path.put()));
        winrt::com_ptr<ID2D1GeometrySink> sink{ nullptr };
        winrt::check_hresult(path->Open(sink.put()));
        sink->SetFillMode(D2D1_FILL_MODE_WINDING);
        sink->BeginFigure({ 18.125F, 2.21000004F }, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddBezier({ { 18.125F, 2.21000004F }, { -24.7329998F, 2.21000004F }, { -24.7329998F, 2.21000004F } });
        sink->AddBezier({ { -24.7329998F, 2.21000004F }, { 0.317999989F, 29.3920002F }, { 0.317999989F, 29.3920002F } });
        sink->AddBezier({ { 0.317999989F, 29.3920002F }, { -2.54699993F, 32.5F }, { -2.54699993F, 32.5F } });
        sink->AddBezier({ { -2.54699993F, 32.5F }, { -32.5F, 0.0F }, { -32.5F, 0.0F } });
        sink->AddBezier({ { -32.5F, 0.0F }, { -2.54699993F, -32.5F }, { -2.54699993F, -32.5F } });
        sink->AddBezier({ { -2.54699993F, -32.5F }, { 0.317999989F, -29.3920002F }, { 0.317999989F, -29.3920002F } });
        sink->AddBezier({ { 0.317999989F, -29.3920002F }, { -24.7329998F, -2.21000004F }, { -24.7329998F, -2.21000004F } });
        sink->AddBezier({ { -24.7329998F, -2.21000004F }, { 18.125F, -2.21000004F }, { 18.125F, -2.21000004F } });
        sink->AddBezier({ { 18.125F, -2.21000004F }, { 18.125F, 2.21000004F }, { 18.125F, 2.21000004F } });
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        winrt::check_hresult(sink->Close());
        auto result = winrt::make_self<CanvasGeometry>(path);
        return result;
    }

    winrt::com_ptr<CanvasGeometry> Geometry_2()
    {
        winrt::com_ptr<ID2D1PathGeometry> path{ nullptr };
        winrt::check_hresult(_d2dFactory->CreatePathGeometry(path.put()));
        winrt::com_ptr<ID2D1GeometrySink> sink{ nullptr };
        winrt::check_hresult(path->Open(sink.put()));
        sink->SetFillMode(D2D1_FILL_MODE_WINDING);
        sink->BeginFigure({ 37.5880013F, 2.16899991F }, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddBezier({ { 37.5880013F, 2.16899991F }, { -24.7329998F, 2.21000004F }, { -24.7329998F, 2.21000004F } });
        sink->AddBezier({ { -24.7329998F, 2.21000004F }, { 0.317999989F, 29.3920002F }, { 0.317999989F, 29.3920002F } });
        sink->AddBezier({ { 0.317999989F, 29.3920002F }, { -2.54699993F, 32.5F }, { -2.54699993F, 32.5F } });
        sink->AddBezier({ { -2.54699993F, 32.5F }, { -32.5F, 0.0F }, { -32.5F, 0.0F } });
        sink->AddBezier({ { -32.5F, 0.0F }, { -2.54699993F, -32.5F }, { -2.54699993F, -32.5F } });
        sink->AddBezier({ { -2.54699993F, -32.5F }, { 0.317999989F, -29.3920002F }, { 0.317999989F, -29.3920002F } });
        sink->AddBezier({ { 0.317999989F, -29.3920002F }, { -24.7329998F, -2.21000004F }, { -24.7329998F, -2.21000004F } });
        sink->AddBezier({ { -24.7329998F, -2.21000004F }, { 37.5880013F, -2.25200009F }, { 37.5880013F, -2.25200009F } });
        sink->AddBezier({ { 37.5880013F, -2.25200009F }, { 37.5880013F, 2.16899991F }, { 37.5880013F, 2.16899991F } });
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        winrt::check_hresult(sink->Close());
        auto result = winrt::make_self<CanvasGeometry>(path);
        return result;
    }

    // - - Shape tree root for layer: Layer 1
    // ShapeGroup: Group 1 Scale:0.95808,0.95808
    CompositionColorBrush ColorBrush_Black()
    {
        return _c.CreateColorBrush({ 0xFF, 0x00, 0x00, 0x00 });
    }

    // Shape tree root for layer: Layer 1
    CompositionContainerShape ContainerShape()
    {
        const auto result = _c.CreateContainerShape();
        // ShapeGroup: Group 1 Scale:0.95808,0.95808
        result.Shapes().Append(SpriteShape());
        StartProgressBoundAnimation(result, L"Offset", OffsetVector2Animation(), _rootProgress);
        return result;
    }

    CompositionPath Path_0()
    {
        const auto result = _path_0 = CompositionPath(CanvasGeometryToIGeometrySource2D(Geometry_0()));
        return result;
    }

    CompositionPath Path_1()
    {
        const auto result = _path_1 = CompositionPath(CanvasGeometryToIGeometrySource2D(Geometry_1()));
        return result;
    }

    CompositionPath Path_2()
    {
        const auto result = _path_2 = CompositionPath(CanvasGeometryToIGeometrySource2D(Geometry_2()));
        return result;
    }

    // - - Shape tree root for layer: Layer 1
    // ShapeGroup: Group 1 Scale:0.95808,0.95808
    CompositionPathGeometry PathGeometry()
    {
        const auto result = _c.CreatePathGeometry();
        StartProgressBoundAnimation(result, L"Path", PathKeyFrameAnimation_0(), RootProgress());
        return result;
    }

    // - Shape tree root for layer: Layer 1
    // Path 1
    CompositionSpriteShape SpriteShape()
    {
        // Scale:<0.95808, 0.95808>
        const auto result = CreateSpriteShape(PathGeometry(), { 0.958079994F, 0.0F, 0.0F, 0.958079994F, 0.0F, 0.0F }, ColorBrush_Black());
        return result;
    }

    // The root of the composition.
    ContainerVisual Root()
    {
        const auto result = _root = _c.CreateContainerVisual();
        const auto propertySet = result.Properties();
        propertySet.InsertScalar(L"Progress", 0.0F);
        propertySet.InsertScalar(L"t0", 0.0F);
        // Shape tree root for layer: Layer 1
        result.Children().InsertAtTop(ShapeVisual_0());
        StartProgressBoundAnimation(propertySet, L"t0", t0ScalarAnimation_0_to_1(), _rootProgress);
        return result;
    }

    CubicBezierEasingFunction CubicBezierEasingFunction_0()
    {
        return _cubicBezierEasingFunction_0 = _c.CreateCubicBezierEasingFunction({ 0.166999996F, 0.166999996F }, { 0.0F, 1.0F });
    }

    ExpressionAnimation RootProgress()
    {
        const auto result = _rootProgress = _c.CreateExpressionAnimation(L"_.Progress");
        result.SetReferenceParameter(L"_", _root);
        return result;
    }

    // - - - Shape tree root for layer: Layer 1
    // - ShapeGroup: Group 1 Scale:0.95808,0.95808
    // Path
    PathKeyFrameAnimation PathKeyFrameAnimation_0()
    {
        const auto result = CreatePathKeyFrameAnimation(0.0F, Path_0(), HoldThenStepEasingFunction());
        result.InsertKeyFrame(0.25F, Path_1(), CubicBezierEasingFunction_0());
        result.InsertKeyFrame(0.333333343F, _path_1, _c.CreateCubicBezierEasingFunction({ 0.0F, 0.0F }, { 1.0F, 1.0F }));
        result.InsertKeyFrame(0.566666663F, Path_2(), _c.CreateCubicBezierEasingFunction({ 0.850000024F, 0.0F }, { 0.0F, 1.0F }));
        result.InsertKeyFrame(0.833333313F, _path_2, _c.CreateCubicBezierEasingFunction({ 0.850000024F, 0.0F }, { 0.833000004F, 0.833000004F }));
        result.InsertKeyFrame(0.983333349F, _path_0, _cubicBezierEasingFunction_0);
        return result;
    }

    ScalarKeyFrameAnimation t0ScalarAnimation_0_to_1()
    {
        const auto result = CreateScalarKeyFrameAnimation(0.50000006F, 0.0F, _stepThenHoldEasingFunction);
        result.SetReferenceParameter(L"_", _root);
        result.InsertKeyFrame(0.816666603F, 1.0F, _c.CreateCubicBezierEasingFunction({ 0.349999994F, 0.0F }, { 0.0F, 1.0F }));
        return result;
    }

    // Shape tree root for layer: Layer 1
    ShapeVisual ShapeVisual_0()
    {
        const auto result = _c.CreateShapeVisual();
        result.Size({ 70.0F, 70.0F });
        result.Shapes().Append(ContainerShape());
        return result;
    }

    StepEasingFunction HoldThenStepEasingFunction()
    {
        const auto result = _holdThenStepEasingFunction = _c.CreateStepEasingFunction();
        result.IsFinalStepSingleFrame(true);
        return result;
    }

    StepEasingFunction StepThenHoldEasingFunction()
    {
        const auto result = _stepThenHoldEasingFunction = _c.CreateStepEasingFunction();
        result.IsInitialStepSingleFrame(true);
        return result;
    }

    // - Shape tree root for layer: Layer 1
    // Offset
    Vector2KeyFrameAnimation OffsetVector2Animation()
    {
        const auto result = CreateVector2KeyFrameAnimation(0.0F, { 35.0470009F, 35.0F }, _holdThenStepEasingFunction);
        result.SetReferenceParameter(L"_", _root);
        result.InsertKeyFrame(0.25F, { 45.2970009F, 35.0F }, _cubicBezierEasingFunction_0);
        result.InsertKeyFrame(0.333333343F, { 45.2970009F, 35.0F }, _c.CreateCubicBezierEasingFunction({ 0.0F, 0.0F }, { 0.0F, 0.0F }));
        result.InsertKeyFrame(0.5F, { 31.2970009F, 35.0F }, _c.CreateCubicBezierEasingFunction({ 0.850000024F, 0.0F }, { 0.75F, 1.0F }));
        result.InsertExpressionKeyFrame(0.816666603F, L"(Pow(1-_.t0,3)*Vector2(31.297,35))+(3*Square(1-_.t0)*_.t0*Vector2(29.13,35))+(3*(1-_.t0)*Square(_.t0)*Vector2(32.13,35))+(Pow(_.t0,3)*Vector2(32.297,35))", StepThenHoldEasingFunction());
        result.InsertKeyFrame(0.816666663F, { 32.2970009F, 35.0F }, _stepThenHoldEasingFunction);
        result.InsertKeyFrame(0.833333313F, { 32.2970009F, 35.0F }, _c.CreateCubicBezierEasingFunction({ 0.850000024F, 0.850000024F }, { 0.833000004F, 0.833000004F }));
        result.InsertKeyFrame(0.983333349F, { 35.0470009F, 35.0F }, _cubicBezierEasingFunction_0);
        return result;
    }

    static IGeometrySource2D CanvasGeometryToIGeometrySource2D(winrt::com_ptr<CanvasGeometry> geo)
    {
        return geo.as<IGeometrySource2D>();
    }

public:
    Controls_08_Back_AnimatedVisual_UAPv11(Compositor compositor)
        : _c{compositor}
        , _reusableExpressionAnimation(compositor.CreateExpressionAnimation())
    {
        winrt::check_hresult(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, _d2dFactory.put()));
        const auto _ = Root();
    }

    void Close()
    {
        if (_root)
        {
            _root.Close();
        }
    }

    TimeSpan Duration() const
    {
        return TimeSpan{ c_durationTicks };
    }

    Visual RootVisual() const
    {
        return _root;
    }

    winrt::float2 Size() const
    {
        return { 70.0F, 70.0F };
    }

    static bool IsRuntimeCompatible()
    {
        return winrt::Windows::Foundation::Metadata::ApiInformation::IsApiContractPresent(L"Windows.Foundation.UniversalApiContract", 11);
    }
};

class Controls_08_Back_AnimatedVisual_UAPv7 : public winrt::implements<Controls_08_Back_AnimatedVisual_UAPv7,
        winrt::Microsoft::UI::Xaml::Controls::IAnimatedVisual,
        IClosable>
{
    winrt::com_ptr<ID2D1Factory> _d2dFactory{ nullptr };
    static constexpr int64_t c_durationTicks{ 10000000L };
    Compositor const _c{ nullptr };
    ExpressionAnimation const _reusableExpressionAnimation{ nullptr };
    ContainerVisual _root{ nullptr };
    CubicBezierEasingFunction _cubicBezierEasingFunction_0{ nullptr };
    ExpressionAnimation _rootProgress{ nullptr };
    StepEasingFunction _stepThenHoldEasingFunction{ nullptr };

    static void StartProgressBoundAnimation(
        CompositionObject target,
        winrt::hstring animatedPropertyName,
        CompositionAnimation animation,
        ExpressionAnimation controllerProgressExpression)
    {
        target.StartAnimation(animatedPropertyName, animation);
        const auto controller = target.TryGetAnimationController(animatedPropertyName);
        controller.Pause();
        controller.StartAnimation(L"Progress", controllerProgressExpression);
    }

    ScalarKeyFrameAnimation CreateScalarKeyFrameAnimation(float initialProgress, float initialValue, CompositionEasingFunction initialEasingFunction)
    {
        const auto result = _c.CreateScalarKeyFrameAnimation();
        result.Duration(TimeSpan{ c_durationTicks });
        result.InsertKeyFrame(initialProgress, initialValue, initialEasingFunction);
        return result;
    }

    Vector2KeyFrameAnimation CreateVector2KeyFrameAnimation(float initialProgress, winrt::float2 initialValue, CompositionEasingFunction initialEasingFunction)
    {
        const auto result = _c.CreateVector2KeyFrameAnimation();
        result.Duration(TimeSpan{ c_durationTicks });
        result.InsertKeyFrame(initialProgress, initialValue, initialEasingFunction);
        return result;
    }

    CompositionSpriteShape CreateSpriteShape(CompositionGeometry geometry, winrt::float3x2 transformMatrix, CompositionBrush fillBrush)
    {
        const auto result = _c.CreateSpriteShape(geometry);
        result.TransformMatrix(transformMatrix);
        result.FillBrush(fillBrush);
        return result;
    }

    // - - - - Shape tree root for layer: Layer 1
    // - - ShapeGroup: Group 1 Scale:0.95808,0.95808
    winrt::com_ptr<CanvasGeometry> Geometry()
    {
        winrt::com_ptr<ID2D1PathGeometry> path{ nullptr };
        winrt::check_hresult(_d2dFactory->CreatePathGeometry(path.put()));
        winrt::com_ptr<ID2D1GeometrySink> sink{ nullptr };
        winrt::check_hresult(path->Open(sink.put()));
        sink->SetFillMode(D2D1_FILL_MODE_WINDING);
        sink->BeginFigure({ 32.5F, 2.21000004F }, D2D1_FIGURE_BEGIN_FILLED);
        sink->AddLine({ -24.7329998F, 2.21000004F });
        sink->AddLine({ 0.317999989F, 29.3920002F });
        sink->AddLine({ -2.54699993F, 32.5F });
        sink->AddLine({ -32.5F, 0.0F });
        sink->AddLine({ -2.54699993F, -32.5F });
        sink->AddLine({ 0.317999989F, -29.3920002F });
        sink->AddLine({ -24.7329998F, -2.21000004F });
        sink->AddLine({ 32.5F, -2.21000004F });
        sink->AddLine({ 32.5F, 2.21000004F });
        sink->EndFigure(D2D1_FIGURE_END_CLOSED);
        winrt::check_hresult(sink->Close());
        auto result = winrt::make_self<CanvasGeometry>(path);
        return result;
    }

    // - - Shape tree root for layer: Layer 1
    // ShapeGroup: Group 1 Scale:0.95808,0.95808
    CompositionColorBrush ColorBrush_Black()
    {
        return _c.CreateColorBrush({ 0xFF, 0x00, 0x00, 0x00 });
    }

    // Shape tree root for layer: Layer 1
    CompositionContainerShape ContainerShape()
    {
        const auto result = _c.CreateContainerShape();
        // ShapeGroup: Group 1 Scale:0.95808,0.95808
        result.Shapes().Append(SpriteShape());
        StartProgressBoundAnimation(result, L"Offset", OffsetVector2Animation(), RootProgress());
        return result;
    }

    // - - Shape tree root for layer: Layer 1
    // ShapeGroup: Group 1 Scale:0.95808,0.95808
    CompositionPathGeometry PathGeometry()
    {
        return _c.CreatePathGeometry(CompositionPath(CanvasGeometryToIGeometrySource2D(Geometry())));
    }

    // - Shape tree root for layer: Layer 1
    // Path 1
    CompositionSpriteShape SpriteShape()
    {
        // Scale:<0.95808, 0.95808>
        const auto result = CreateSpriteShape(PathGeometry(), { 0.958079994F, 0.0F, 0.0F, 0.958079994F, 0.0F, 0.0F }, ColorBrush_Black());
        return result;
    }

    // The root of the composition.
    ContainerVisual Root()
    {
        const auto result = _root = _c.CreateContainerVisual();
        const auto propertySet = result.Properties();
        propertySet.InsertScalar(L"Progress", 0.0F);
        propertySet.InsertScalar(L"t0", 0.0F);
        // Shape tree root for layer: Layer 1
        result.Children().InsertAtTop(ShapeVisual_0());
        StartProgressBoundAnimation(propertySet, L"t0", t0ScalarAnimation_0_to_1(), _rootProgress);
        return result;
    }

    CubicBezierEasingFunction CubicBezierEasingFunction_0()
    {
        return _cubicBezierEasingFunction_0 = _c.CreateCubicBezierEasingFunction({ 0.166999996F, 0.166999996F }, { 0.0F, 1.0F });
    }

    ExpressionAnimation RootProgress()
    {
        const auto result = _rootProgress = _c.CreateExpressionAnimation(L"_.Progress");
        result.SetReferenceParameter(L"_", _root);
        return result;
    }

    ScalarKeyFrameAnimation t0ScalarAnimation_0_to_1()
    {
        const auto result = CreateScalarKeyFrameAnimation(0.50000006F, 0.0F, _stepThenHoldEasingFunction);
        result.SetReferenceParameter(L"_", _root);
        result.InsertKeyFrame(0.816666603F, 1.0F, _c.CreateCubicBezierEasingFunction({ 0.349999994F, 0.0F }, { 0.0F, 1.0F }));
        return result;
    }

    // Shape tree root for layer: Layer 1
    ShapeVisual ShapeVisual_0()
    {
        const auto result = _c.CreateShapeVisual();
        result.Size({ 70.0F, 70.0F });
        result.Shapes().Append(ContainerShape());
        return result;
    }

    // - - Shape tree root for layer: Layer 1
    // Offset
    StepEasingFunction HoldThenStepEasingFunction()
    {
        const auto result = _c.CreateStepEasingFunction();
        result.IsFinalStepSingleFrame(true);
        return result;
    }

    StepEasingFunction StepThenHoldEasingFunction()
    {
        const auto result = _stepThenHoldEasingFunction = _c.CreateStepEasingFunction();
        result.IsInitialStepSingleFrame(true);
        return result;
    }

    // - Shape tree root for layer: Layer 1
    // Offset
    Vector2KeyFrameAnimation OffsetVector2Animation()
    {
        const auto result = CreateVector2KeyFrameAnimation(0.0F, { 35.0470009F, 35.0F }, HoldThenStepEasingFunction());
        result.SetReferenceParameter(L"_", _root);
        result.InsertKeyFrame(0.25F, { 45.2970009F, 35.0F }, CubicBezierEasingFunction_0());
        result.InsertKeyFrame(0.333333343F, { 45.2970009F, 35.0F }, _c.CreateCubicBezierEasingFunction({ 0.0F, 0.0F }, { 0.0F, 0.0F }));
        result.InsertKeyFrame(0.5F, { 31.2970009F, 35.0F }, _c.CreateCubicBezierEasingFunction({ 0.850000024F, 0.0F }, { 0.75F, 1.0F }));
        result.InsertExpressionKeyFrame(0.816666603F, L"(Pow(1-_.t0,3)*Vector2(31.297,35))+(3*Square(1-_.t0)*_.t0*Vector2(29.13,35))+(3*(1-_.t0)*Square(_.t0)*Vector2(32.13,35))+(Pow(_.t0,3)*Vector2(32.297,35))", StepThenHoldEasingFunction());
        result.InsertKeyFrame(0.816666663F, { 32.2970009F, 35.0F }, _stepThenHoldEasingFunction);
        result.InsertKeyFrame(0.833333313F, { 32.2970009F, 35.0F }, _c.CreateCubicBezierEasingFunction({ 0.850000024F, 0.850000024F }, { 0.833000004F, 0.833000004F }));
        result.InsertKeyFrame(0.983333349F, { 35.0470009F, 35.0F }, _cubicBezierEasingFunction_0);
        return result;
    }

    static IGeometrySource2D CanvasGeometryToIGeometrySource2D(winrt::com_ptr<CanvasGeometry> geo)
    {
        return geo.as<IGeometrySource2D>();
    }

public:
    Controls_08_Back_AnimatedVisual_UAPv7(Compositor compositor)
        : _c{compositor}
        , _reusableExpressionAnimation(compositor.CreateExpressionAnimation())
    {
        winrt::check_hresult(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, _d2dFactory.put()));
        const auto _ = Root();
    }

    void Close()
    {
        if (_root)
        {
            _root.Close();
        }
    }

    TimeSpan Duration() const
    {
        return TimeSpan{ c_durationTicks };
    }

    Visual RootVisual() const
    {
        return _root;
    }

    winrt::float2 Size() const
    {
        return { 70.0F, 70.0F };
    }

    static bool IsRuntimeCompatible()
    {
        return winrt::Windows::Foundation::Metadata::ApiInformation::IsApiContractPresent(L"Windows.Foundation.UniversalApiContract", 7);
    }
};

winrt::Microsoft::UI::Xaml::Controls::IAnimatedVisual Controls_08_Back::TryCreateAnimatedVisual(
    Compositor const& compositor,
    IInspectable& diagnostics)
{
    diagnostics = nullptr;

    if (Controls_08_Back_AnimatedVisual_UAPv11::IsRuntimeCompatible())
    {
        return winrt::make<Controls_08_Back_AnimatedVisual_UAPv11>(compositor);
    }

    if (Controls_08_Back_AnimatedVisual_UAPv7::IsRuntimeCompatible())
    {
        return winrt::make<Controls_08_Back_AnimatedVisual_UAPv7>(compositor);
    }

    return nullptr;
}

winrt::Microsoft::UI::Xaml::Controls::IAnimatedVisual Controls_08_Back::TryCreateAnimatedIconVisual(
    Compositor const& compositor)
{
    IInspectable diagnostics;
    return TryCreateAnimatedVisual(compositor, diagnostics);
}

double Controls_08_Back::FrameToProgress(double frameNumber)
{
    return frameNumber / 60.0;
}

winrt::Windows::Foundation::Collections::IMapView<hstring, double> Controls_08_Back::Markers()
{
    return winrt::single_threaded_map<winrt::hstring, double>(
        std::map<winrt::hstring, double>
        {
            { L"NormalToHover_Start", 0.0 },
            { L"NormalToHover_End", 0.303 },
            { L"NormalToPressed_Start", 0.0 },
            { L"NormalToPressed_End", 0.810 },
            { L"HoverToNormal_Start", 0.303 },
            { L"HoverToNormal_End", 0.0 },
            { L"HoverToPressed_Start", 0.303 },
            { L"HoverToPressed_End", 0.810 },
            { L"PressedToNormal_Start", 0.810 },
            { L"PressedToNormal_End", 1.0 },
            { L"PressedToHover_Start", 0.810 },
            { L"PressedToHover_End", 0.303 },
        }
    ).GetView();
}

void Controls_08_Back::SetColorProperty(hstring const&, Color)
{
}

void Controls_08_Back::SetScalarProperty(hstring const&, double)
{
}
