struct VS_INPUT
{
    float4 position : POSITION0;
    float2 texcoord : TEXCOORD0;
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;
    float2 texcoord : TEXCOORD0;
};


cbuffer constant : register(b0)
{
    row_major float4x4 m_world;
    row_major float4x4 m_view;
    row_major float4x4 m_proj;
    unsigned int m_time;
}


VS_OUTPUT vsmain(VS_INPUT input)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    
    //output.position = lerp(input.position, input.position1, (sin(m_time / 1000.0f) + 1.0f) / 2.0f);
    
    //WORLD SPACE
    output.position = mul(input.position, m_world);
    //VIEW SPACE
    output.position = mul(output.position, m_view);
    //SCREEN SPACE
    output.position = mul(output.position, m_proj);
    
    
    output.texcoord = input.texcoord;
    return output;
}