using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class gezi : MonoBehaviour
{
    [SerializeField]
    Image image1;
    Image image2;

    
    float y;
    //[SerializeField]
    int x=0;
    //imagech.cs�ɒl��n���ϐ�
    public static int image_ch=0;

    /*
    //�f�o�b�N�p
    [SerializeField]
    public float xa = 0;
    */


    // Start is called before the first frame update
    void Start()
    {
        image2 = GetComponent<Image>();
    }

    // Update is called once per frame
    void Update()
    {
        //fire.cs�̕ϐ�a��x�ɑ��
        x = (int)fire.a;

        // Fill Amount�ɂ���ăQ�[�W�̐F��ς���
        //60�x�ȏ�̎��ɃQ�[�W��ԐF�ɂ���
        if (image2.fillAmount >= 0.6f)
        {

            image1.color = Color.red;
            image_ch = 2;

        }
        //30�x�ȏ�̎��ɃQ�[�W�����F�ɂ���
        else if (image2.fillAmount >= 0.3f)
        {
            image1.color = Color.yellow;
            image_ch = 1;
        }
        //29�x�ȉ��̎��ɃQ�[�W�����ΐF�ɂ���
        else
        {
            image1.color = Color.green;
            image_ch = 0;
        }

        
          y = (float)x / 100;

          y = y * -1;
         image2.fillAmount = y;
         
        /*
        //�f�o�b�N�p
        image2.fillAmount = xa;
        */
    }

}