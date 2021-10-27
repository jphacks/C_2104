using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;
using System;

public class RigControl : MonoBehaviour
{
    float x;
    public GameObject humanoid;
    public Vector3 bodyRotation = new Vector3(0, 0, 0);
    public Vector3 bodyPosition = new Vector3(0,0,0);

    //Bone�̃f�[�^������ϐ�
    RigBone Neck;

   
    
    void Start()
    {
        //�ϐ��Ƀ{�[���̃f�[�^����
        Neck = new RigBone(humanoid, HumanBodyBones.Neck);
    }
    void Update()
    {
        //fire.cs�̕ϐ�a��x�ɑ��
        x = fire.a;
       
      //  Debug.Log("copy pose is " + x);
        //x = -45;

        //��U��@�\
        Neck.set((x), 0, 0, 1);

        humanoid.transform.rotation
          = Quaternion.AngleAxis(bodyRotation.z, new Vector3(0, 0, 1))
          * Quaternion.AngleAxis(bodyRotation.x, new Vector3(1, 0, 0))
          * Quaternion.AngleAxis(bodyRotation.y, new Vector3(0, 1, 0));
    }
}