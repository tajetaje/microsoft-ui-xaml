// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#include "pch.h"
#include "common.h"
#include "Breadcrumb.h"

namespace winrt::Microsoft::UI::Xaml::Controls
{
    CppWinRTActivatableClassWithDPFactory(Breadcrumb)
}

#include "Breadcrumb.g.cpp"

GlobalDependencyProperty BreadcrumbProperties::s_ItemsSourceProperty{ nullptr };
GlobalDependencyProperty BreadcrumbProperties::s_ItemTemplateProperty{ nullptr };

BreadcrumbProperties::BreadcrumbProperties()
    : m_itemClickedEventSource{static_cast<Breadcrumb*>(this)}
{
    EnsureProperties();
}

void BreadcrumbProperties::EnsureProperties()
{
    if (!s_ItemsSourceProperty)
    {
        s_ItemsSourceProperty =
            InitializeDependencyProperty(
                L"ItemsSource",
                winrt::name_of<winrt::IInspectable>(),
                winrt::name_of<winrt::Breadcrumb>(),
                false /* isAttached */,
                ValueHelper<winrt::IInspectable>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnItemsSourcePropertyChanged));
    }
    if (!s_ItemTemplateProperty)
    {
        s_ItemTemplateProperty =
            InitializeDependencyProperty(
                L"ItemTemplate",
                winrt::name_of<winrt::IInspectable>(),
                winrt::name_of<winrt::Breadcrumb>(),
                false /* isAttached */,
                ValueHelper<winrt::IInspectable>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnItemTemplatePropertyChanged));
    }
}

void BreadcrumbProperties::ClearProperties()
{
    s_ItemsSourceProperty = nullptr;
    s_ItemTemplateProperty = nullptr;
}

void BreadcrumbProperties::OnItemsSourcePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::Breadcrumb>();
    winrt::get_self<Breadcrumb>(owner)->OnPropertyChanged(args);
}

void BreadcrumbProperties::OnItemTemplatePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::Breadcrumb>();
    winrt::get_self<Breadcrumb>(owner)->OnPropertyChanged(args);
}

void BreadcrumbProperties::ItemsSource(winrt::IInspectable const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<Breadcrumb*>(this)->SetValue(s_ItemsSourceProperty, ValueHelper<winrt::IInspectable>::BoxValueIfNecessary(value));
    }
}

winrt::IInspectable BreadcrumbProperties::ItemsSource()
{
    return ValueHelper<winrt::IInspectable>::CastOrUnbox(static_cast<Breadcrumb*>(this)->GetValue(s_ItemsSourceProperty));
}

void BreadcrumbProperties::ItemTemplate(winrt::IInspectable const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<Breadcrumb*>(this)->SetValue(s_ItemTemplateProperty, ValueHelper<winrt::IInspectable>::BoxValueIfNecessary(value));
    }
}

winrt::IInspectable BreadcrumbProperties::ItemTemplate()
{
    return ValueHelper<winrt::IInspectable>::CastOrUnbox(static_cast<Breadcrumb*>(this)->GetValue(s_ItemTemplateProperty));
}

winrt::event_token BreadcrumbProperties::ItemClicked(winrt::TypedEventHandler<winrt::Breadcrumb, winrt::BreadcrumbItemClickedEventArgs> const& value)
{
    return m_itemClickedEventSource.add(value);
}

void BreadcrumbProperties::ItemClicked(winrt::event_token const& token)
{
    m_itemClickedEventSource.remove(token);
}
