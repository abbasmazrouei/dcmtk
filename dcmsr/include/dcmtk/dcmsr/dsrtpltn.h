/*
 *
 *  Copyright (C) 2015, J. Riesmeier, Oldenburg, Germany
 *  All rights reserved.  See COPYRIGHT file for details.
 *
 *  This software and supporting documentation are maintained by
 *
 *    OFFIS e.V.
 *    R&D Division Health
 *    Escherweg 2
 *    D-26121 Oldenburg, Germany
 *
 *
 *  Module: dcmsr
 *
 *  Author: Joerg Riesmeier
 *
 *  Purpose:
 *    classes: DSRIncludedTemplateTreeNode
 *
 */


#ifndef DSRTPLTN_H
#define DSRTPLTN_H

#include "dcmtk/config/osconfig.h"   /* make sure OS specific configuration is included first */

#include "dcmtk/dcmsr/dsrdoctn.h"
#include "dcmtk/dcmsr/dsrstpl.h"


/*---------------------*
 *  class declaration  *
 *---------------------*/

/** Class for managing included templates (internal)
 */
class DCMTK_DCMSR_EXPORT DSRIncludedTemplateTreeNode
  : public DSRDocumentTreeNode
{
    // allow DSRDocumentSubTree to access protected method getValuePtr()
    friend class DSRDocumentSubTree;

  public:

    /** constructor
     ** @param  referencedTemplate  shared pointer to template that should be managed
     *  @param  defaultRelType      default relationship type of the included template
     */
    DSRIncludedTemplateTreeNode(const DSRSharedSubTemplate &referencedTemplate,
                                const E_RelationshipType defaultRelType);

    /** copy constructor.
     *  Please note that the comments on the copy constructor of the base class
     *  DSRDocumentTreeNode apply.
     ** @param  node  tree node to be copied
     */
    DSRIncludedTemplateTreeNode(const DSRIncludedTemplateTreeNode &node);

    /** destructor
     */
    virtual ~DSRIncludedTemplateTreeNode();

    /** clone this tree node.
     *  Internally, the copy constructor is used, so the corresponding comments apply.
     ** @return copy of this tree node
     */
    virtual DSRIncludedTemplateTreeNode *clone() const;

    /** clear all member variables.
     *  Please note that the content item becomes invalid afterwards.
     */
    virtual void clear();

    /** check whether the content item is valid.
     *  The content item is valid if the base class is valid and the reference to the
     *  included template is valid.
     ** @return OFTrue if tree node is valid, OFFalse otherwise
     */
    virtual OFBool isValid() const;

    /** check whether the value of the content item, i.e.\ the reference to the included
     *  template is valid.
     ** @return OFTrue if the value is valid, OFFalse otherwise
     */
    virtual OFBool hasValidValue() const;

    /** print content item.
     *  A typical output looks like this: # INCLUDE TID 1600 (DCMR)
     *  In contrast to other classes that are derived from DSRDocumentTreeNode,
     *  this method prints a separate line, but if and only if the 'flag'
     *  DSRTypes::PF_printIncludedTemplateNode is set.
     ** @param  stream  output stream to which the content item should be printed
     *  @param  flags   flag used to customize the output (see DSRTypes::PF_xxx)
     ** @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition print(STD_NAMESPACE ostream &stream,
                              const size_t flags) const;

    /** print content of included template
     ** @param  stream      output stream to which the template should be printed
     *  @param  flags       flag used to customize the output (see DSRTypes::PF_xxx)
     *  @param  linePrefix  string that is prepended to each output line (optional)
     ** @return status, EC_Normal if successful, an error code otherwise
     */
    virtual OFCondition printTemplate(STD_NAMESPACE ostream &stream,
                                      const size_t flags,
                                      const OFString &linePrefix) const;


  protected:

    /** get pointer to included template, i.e.\ the value of this content item
     ** @return pointer to included template (might be NULL)
     */
    inline const DSRSubTemplate *getValuePtr() const
    {
        return ReferencedTemplate.get();
    }

    /** set the concept name
     ** @param  conceptName  dummy parameter
     *  @param  check        dummy parameter
     ** @return always returns EC_IllegalCall, since this method should not be called
     */
    virtual OFCondition setConceptName(const DSRCodedEntryValue &conceptName,
                                       const OFBool check = OFTrue);

    /** set observation date/time
     ** @param  observationDateTime  dummy parameter
     *  @param  check                dummy parameter
     ** @return always returns EC_IllegalCall, since this method should not be called
     */
    virtual OFCondition setObservationDateTime(const OFString &observationDateTime,
                                               const OFBool check = OFTrue);

    /** set observation date/time from element
     ** @param  delem  dummy parameter
     *  @param  pos    dummy parameter
     *  @param  check  dummy parameter
     ** @return always returns EC_IllegalCall, since this method should not be called
     */
    virtual OFCondition setObservationDateTime(const DcmElement &delem,
                                               const unsigned long pos = 0,
                                               const OFBool check = OFTrue);

    /** set observation date/time from dataset
     ** @param  dataset  dummy parameter
     *  @param  tagKey   dummy parameter
     *  @param  pos      dummy parameter
     *  @param  check    dummy parameter
     ** @return always returns EC_IllegalCall, since this method should not be called
     */
    virtual OFCondition setObservationDateTime(DcmItem &dataset,
                                               const DcmTagKey &tagKey,
                                               const unsigned long pos = 0,
                                               const OFBool check = OFTrue);

    /** set observation unique identifier
     ** @param  observationUID  dummy parameter
     *  @param  check           dummy parameter
     ** @return always returns EC_IllegalCall, since this method should not be called
     */
    virtual OFCondition setObservationUID(const OFString &observationUID,
                                          const OFBool check = OFTrue);

    /** set template identifier and mapping resource
     ** @param  templateIdentifier  dummy parameter
     *  @param  mappingResource     dummy parameter
     *  @param  mappingResourceUID  dummy parameter
     *  @param  check               dummy parameter
     ** @return always returns EC_IllegalCall, since this method should not be called
     */
    virtual OFCondition setTemplateIdentification(const OFString &templateIdentifier,
                                                  const OFString &mappingResource,
                                                  const OFString &mappingResourceUID = "",
                                                  const OFBool check = OFTrue);


  private:

    /// shared pointer to included template that is managed by this class
    DSRSharedSubTemplate ReferencedTemplate;


 // --- declaration of default constructor and assignment operator

    DSRIncludedTemplateTreeNode();
    DSRIncludedTemplateTreeNode &operator=(const DSRIncludedTemplateTreeNode &);
};


#endif