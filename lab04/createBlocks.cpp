#include "blocks.h"

void createBlocks(vector<rectBlocks> &_rectBlocks, vector<sqrBaseRectBlocks> &_sqrBaseRectBlocks, 
    vector<cuboidBlocks> &_cuboidBlocks, vector<cylindricalBlocks> &_cylindricalBlocks, 
    vector<sphericalBlocks> &_sphericalBlocks){

    for(int i=0; i<_rectBlocks.size(); i++){
        int w = _rectBlocks[i].width;
        int h = _rectBlocks[i].height;
        int l = _rectBlocks[i].length;

        if(w==h){

            //assigning members to sqrBaseRectBlocks vector
            sqrBaseRectBlocks _sbrb(w,l);
            _sqrBaseRectBlocks.push_back(_sbrb);

            //assigning members to cylindricalBlocks vector
            cylindricalBlocks _cyb(w,l);
            _cylindricalBlocks.push_back(_cyb);

            //assigning members to cubiodBlocks vector
            if(h==l){
                cuboidBlocks _cub(w);
                _cuboidBlocks.push_back(_cub);

                //assigning members to the sphericalBlock vector
                sphericalBlocks _sb(w);
                _sphericalBlocks.push_back(_sb);
            }
        }
    }
}