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
    //imagech.csに値を渡す変数
    public static int image_ch=0;

    /*
    //デバック用
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
        //fire.csの変数aをxに代入
        x = (int)fire.a;

        // Fill Amountによってゲージの色を変える
        //60度以上の時にゲージを赤色にする
        if (image2.fillAmount >= 0.6f)
        {

            image1.color = Color.red;
            image_ch = 2;

        }
        //30度以上の時にゲージを黄色にする
        else if (image2.fillAmount >= 0.3f)
        {
            image1.color = Color.yellow;
            image_ch = 1;
        }
        //29度以下の時にゲージを黄緑色にする
        else
        {
            image1.color = Color.green;
            image_ch = 0;
        }

        
          y = (float)x / 100;

          y = y * -1;
         image2.fillAmount = y;
         
        /*
        //デバック用
        image2.fillAmount = xa;
        */
    }

}