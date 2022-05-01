// 輸入一個頂點坐標, 類型為 POSITION
// 輸出一個頂點坐標(已着色的), 類型為 SV_POSITION
float4 VS_Main( float4 pos : POSITION ) : SV_POSITION
{
    // 直接返回輸入的參數值 pos
    return pos;
}


//輸入一個 頂點坐標( 已着色的), 類型為 SV_POSITION
//輸出一個 可直接顯示在目標上的 顏色( 已着色的), 類型為 SV_TARGET
float4 PS_Main( float4 pos : SV_POSITION ) : SV_TARGET
{
    // 直接返回 固定的顏色, 輸入值 pos 不做任何處理
    return float4( 0.0f, 1.0f, 0.0f, 1.0f );
}

//注意 , 上述的 ( 已着色的) 是指 shadered.