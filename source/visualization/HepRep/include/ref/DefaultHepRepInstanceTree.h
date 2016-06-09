#ifndef DEFAULTHEPREPINSTANCETREE_H
#define DEFAULTHEPREPINSTANCETREE_H 1

#include "FreeHepTypes.h"

#include <string>
#include <vector>
#include <set>

#include "HEPREP/HepRep.h"
#include "HEPREP/HepRepSelectFilter.h"
#include "HEPREP/HepRepInstanceTree.h"
#include "HEPREP/HepRepInstance.h"
#include "HEPREP/HepRepWriter.h"
#include "HEPREP/HepRepTreeID.h"

#include "DefaultHepRepTreeID.h"

/**
 *
 * @author M.Donszelmann
 */
class DefaultHepRepInstanceTree : public DefaultHepRepTreeID, public virtual HEPREP::HepRepInstanceTree {

    private:
        HEPREP::HepRepTreeID* typeTree;
        std::vector<HEPREP::HepRepInstance*> instances;
        std::vector<HEPREP::HepRepTreeID*> instanceTrees;

    public:
        DefaultHepRepInstanceTree(std::string name, std::string version, HEPREP::HepRepTreeID* typeTree);
        ~DefaultHepRepInstanceTree();

        void overlay(HEPREP::HepRepInstanceTree * instanceTree);
        HEPREP::HepRepInstanceTree* copy(HEPREP::HepRepTypeTree* typeTree, HEPREP::HepRepSelectFilter* filter);
        void addInstance(HEPREP::HepRepInstance* instance);
        void removeInstance(HEPREP::HepRepInstance* instance);
        std::vector<HEPREP::HepRepInstance*> getInstances();
        void addInstanceTree(HEPREP::HepRepTreeID* treeID);
        HEPREP::HepRepTreeID* getTypeTree();
        std::vector<HEPREP::HepRepTreeID*> getInstanceTreeList();
};

#endif