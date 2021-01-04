// This file is part of the Acts project.
//
// Copyright (C) 2020 CERN for the benefit of the Acts project
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "ActsExamples/TelescopeDetector/TelescopeDetectorOptions.hpp"

#include "ActsExamples/Utilities/Options.hpp"

#include <boost/program_options.hpp>

void ActsExamples::Options::addTelescopeGeometryOptions(
    ActsExamples::Options::Description& desc) {
  using boost::program_options::value;
  auto opt = desc.add_options();
  opt("geo-tele-positions",
      value<read_range>()->multitoken()->default_value(
          {0, 30, 60, 120, 150, 180}),
      "Telescope detector Input: the layers positions in the longidutinal "
      "direction in mm");
  opt("geo-tele-offsets",
      value<read_range>()->multitoken()->default_value({0, 0}),
      "Telescope detector Input: the layers offsets in the transverse plane in "
      "mm. Same values for "
      "all layers");
  opt("geo-tele-size",
      value<read_range>()->multitoken()->default_value({50, 25}),
      "Telescope detector Input: the size of each plane in local x and y "
      "directions in mm");
  opt("geo-tele-thickness", value<double>()->default_value(80),
      "Telescope detector Input: the silicon material thickness of "
      "each layer in um. Same value for all layers");
  opt("geo-tele-alignaxis", value<size_t>()->default_value(2),
      "Telescope detector Input: the detector is placed along which "
      "axis: 0 - x axis, 1 - y axis, 2 - z aixs");
}