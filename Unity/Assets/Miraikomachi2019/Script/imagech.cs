using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class imagech : MonoBehaviour
{
    // Image �R���|�[�l���g���i�[����ϐ�
    private Image m_Image;
    // �X�v���C�g�I�u�W�F�N�g���i�[����z��
    public Sprite[] m_Sprite;
    // �X�v���C�g�I�u�W�F�N�g��ύX���邽�߂̕ϐ�
    int a;

    //�����p�֐�
    //public AudioClip sound1;
    private AudioSource audioSource;

    // �Q�[���J�n���Ɏ��s���鏈��
    void Start()
    {
        // Image �R���|�[�l���g���擾
        m_Image = GetComponent<Image>();

        //audio�R���|�[�l���g���擾
        audioSource = GetComponent<AudioSource>();
    }

    // �Q�[�����s���ɖ��t���[�����s���鏈��
    void Update()
    {
        //gezi.cs�̕ϐ�image_ch��a�ɑ��
        a =gezi.image_ch;

        
        // �X�v���C�g�I�u�W�F�N�g�̕ύX�t���O�� true �̏ꍇ
        if (a == 0)
            {
                // �X�v���C�g�I�u�W�F�N�g�̕ύX
                m_Image.sprite = m_Sprite[0];
                
            }
            else if (a == 1)
            {
                //Debug.Log("copy pose is " + a);
                m_Image.sprite = m_Sprite[1];
                //("���s����֐�",�����b��Ɏ��s)
                 Invoke("sound", 5);
            }
            // �X�v���C�g�I�u�W�F�N�g�̕ύX�t���O�� false �̏ꍇ
               else if(a==2)
            {
            
                 // �X�v���C�g�I�u�W�F�N�g�̕ύX
                 m_Image.sprite = m_Sprite[2];
             }
        }
    
    void sound() {
        //GetComponent<AudioSource>().Play();
         audioSource.Play();
    }
    
}



