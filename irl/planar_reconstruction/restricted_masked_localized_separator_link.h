// This file is part of the Interface Reconstruction Library (IRL),
// a library for interface reconstruction and computational geometry operations.
//
// Copyright (C) 2019 Robert Chiodi <robert.chiodi@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef IRL_PLANAR_RECONSTRUCTION_RESTRICTED_MASKED_LOCALIZED_SEPARATOR_LINK_H_
#define IRL_PLANAR_RECONSTRUCTION_RESTRICTED_MASKED_LOCALIZED_SEPARATOR_LINK_H_

#include <unordered_map>

#include "irl/graphs/un_directed_graph_node.h"
#include "irl/planar_reconstruction/planar_localizer.h"
#include "irl/planar_reconstruction/masked_localized_separator_link.h"
#include "irl/planar_reconstruction/localized_separator_link.h"
#include "irl/planar_reconstruction/planar_separator.h"

namespace IRL {

class RestrictedMaskedLocalizedSeparatorLink
    : public StolenGraph<RestrictedMaskedLocalizedSeparatorLink,
                         LocalizedSeparatorLink> {
  using WhiteListType = std::unordered_map<const LocalizedSeparatorLink*, bool>;

 public:
  /// \brief Default constructor
  RestrictedMaskedLocalizedSeparatorLink(void) = delete;

  /// \brief Construct with pointer to LocalizedSeparatorLink.
  // Also have pointer to a_separator that will always be used
  // to divide the localized regions
  RestrictedMaskedLocalizedSeparatorLink(
      const LocalizedSeparatorLink* a_localized_separator_link,
      const PlanarSeparator* a_separator, const WhiteListType* a_white_list);

  bool hasNeighbor(const UnsignedIndex_t a_neighbor_index) const;

  RestrictedMaskedLocalizedSeparatorLink getNeighbor(
      const UnsignedIndex_t a_neighbor_index) const;

  const PlanarLocalizer& getCurrentReconstruction(void) const;

  const PlanarSeparator& getNextReconstruction(void) const;

  /// \brief Return address of the thing that is linked.
  const LocalizedSeparatorLink* getLinkingReconstructionAddress(void) const;

  /// \brief Default destructor.
  ~RestrictedMaskedLocalizedSeparatorLink(void) = default;

 private:
  const PlanarSeparator* separator_m;
  const WhiteListType* white_list_m;
};

}  // namespace IRL

#include "irl/planar_reconstruction/restricted_masked_localized_separator_link.tpp"

#endif // IRL_PLANAR_RECONSTRUCTION_RESTRICTED_MASKED_LOCALIZED_SEPARATOR_LINK_H_
